#include "QuestionsManager.h"
using namespace std;

void QuestionsManager::LoadDataBase() {
    idquestion_idthread.clear();
    string path = "questions.txt";
    vector<string>lines = helperFunctions.ReadFileLines(path);
    for(auto &line : lines){
        auto spilt = helperFunctions.SpiltString(line);
        Question question(spilt);
        int question_id = question.GetQuestionId();
        int parent = question.GetParentQuestionId();
        if(parent == -1) {
            idquestion_idthread[question_id].push_back(question_id);
        } else{
            idquestion_idthread[parent].push_back(question_id);
        }
        GetQuestionUsingId[question.GetQuestionId()] = question;
        last_id = max(last_id , question_id);
    }
}

void QuestionsManager::UpdateDataBase() {
    vector<string>lines;
    for(auto &[question_id , question] : GetQuestionUsingId){
        string s = question.ToString();
        lines.push_back(s);
    }
    string path = "questions.txt";
    helperFunctions.WriteFileLines(path , lines , false);
}

void QuestionsManager::ReadQuestion(const int &id_from ,const int &id_to, const int &IsAnonymous) {
    if(IsAnonymous == 0){
        cout << "Note : Anonymous questions are ont allowed for this user\n";
    }
    cout << "For thread question: Enter Question id or -1 for new question:";
    int id;
    cin >> id;
    Question question;
    cout << "\nEnter question text:";
    string question_text;
    getline(cin , question_text);
    getline(cin , question_text);
    question.SetQuestionText(question_text);
    question.SetQuestionId(++last_id);
    question.SetIdFrom(id_from);
    question.SetIdTo(id_to);
    if(IsAnonymous){
        cout << "Enter 1 to make anonymous question and 0 otherwise :";
        int anonymous;
        cin >> anonymous;
        question.SetAnonymousQuestion(anonymous);
        cout <<"\n";
    }
    if(id == -1){
        idquestion_idthread[question.GetQuestionId()].push_back(question.GetQuestionId());
    }else{
        question.SetParentQuestionId(id);
        idquestion_idthread[id].push_back(question.GetQuestionId());
    }
    GetQuestionUsingId[question.GetQuestionId()] = question;
}
pair<vector<int> , map < int , vector<int> > > QuestionsManager::ResetQuestionsFrom_To(const User &current_user) {
    vector<int> id_from_me;
    map < int , vector<int> > id_to_me;
    int id = current_user.GetId();
    for(auto &[id_question, id_thread] : idquestion_idthread){
        for(auto &ids:id_thread){
            Question question = GetQuestionUsingId[ids];
            if(question.GetIdFrom() == id){
                id_from_me.push_back(ids);
            }
        }
        Question question = GetQuestionUsingId[id_question];
        if(question.GetIdTo() == id){
            id_to_me[id_question] = id_thread;
        }
    }
    return {id_from_me , id_to_me};
}
void QuestionsManager::PrintQuestionsFromUser(const User &user) {
    const auto &id_questions = user.GetIdQuestionsFromMe();
    for(auto &id_question : id_questions){
        const auto &question = GetQuestionUsingId[id_question];
        question.PrintQuestion(1);
    }
}
void QuestionsManager::PrintQuestionsToUser(const User &user) {
    const auto &id_questions_id_threads = user.GetIdQuestionsToMe();
    for(auto &[id_parent , ids_threads] : id_questions_id_threads){
        for(auto &id_question:ids_threads){
            const auto &question = GetQuestionUsingId[id_question];
            question.PrintQuestion(2);
        }
    }
}
void QuestionsManager::DeleteQuestion() {
    cout << "Enter question id or -1 to cancel:";
    int id; cin >> id;
    if(id != -1){
        if(GetQuestionUsingId[id].GetQuestionId() == -1){
            cout << "Invalid Id, Try again.\n";
            DeleteQuestion();
            return;
        }
        map < int , Question > CopyGetUsingId;
        map < int , vector<int> > CopyGetId_IdsThreads;
        for(auto &[question_id , question] : GetQuestionUsingId){
            if(id == question_id)continue;
            CopyGetUsingId[question_id] = question;
            if(question.GetParentQuestionId() == -1){
                CopyGetId_IdsThreads[question_id].push_back(question_id);
            }else{
                CopyGetId_IdsThreads[question.GetParentQuestionId()].push_back(question_id);
            }
        }
        GetQuestionUsingId.clear();
        GetQuestionUsingId = CopyGetUsingId;
        idquestion_idthread.clear();
        idquestion_idthread = CopyGetId_IdsThreads;
    }
}
void QuestionsManager::AnswerQuestion(const int &user_id) {
    cout << "Enter question id or -1 to cancel:";
    int id ; cin >> id;
    if(id != -1){
        bool found = false;
        for(auto &[question_id , question] : GetQuestionUsingId){
            if(question_id == id && user_id == question.GetIdTo()) found = true;
        }
        if(!found){
            cout << "Invalid Id, Try again.\n";
            AnswerQuestion(user_id);
            return;
        }
        auto &question = GetQuestionUsingId[id];
        question.PrintQuestion(2);
        if(question.GetAnswerText() != ""){
            cout << "Warning : Already answered, Answer will be update.\n";
        }
        cout << "Enter Answer :";
        string answer;
        getline(cin , answer);
        getline(cin , answer);
        question.SetAnswerText(answer);
    }
}
void QuestionsManager::ListOfQuestions()  {
    for(auto &[threads_parent , threads_ids] : idquestion_idthread){
        for(auto &id_question : threads_ids){
            const auto &question = GetQuestionUsingId[id_question];
            question.PrintQuestion(3);
        }
    }
}