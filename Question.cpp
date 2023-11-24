#include "Question.h"
using namespace  std;

Question::Question():from_user_id(-1),to_user_id(-1),question_id(-1),question_text(""),answer_text(""),is_anonymous_questions(0),parent_question_id(-1) {
}

Question::Question(vector<string>&str) {
    //assert(str.size() == 7);
    SetQuestionId(stoi(str[0]));
    SetParentQuestionId(stoi(str[1]));
    SetIdFrom(helperFunctions.ToInt(str[2]));
    SetIdTo(stoi(str[3]));
    SetAnonymousQuestion(stoi(str[4]));
    SetQuestionText(str[5]);
    SetAnswerText(str[6]);
}

int Question::GetIdFrom() const {
    return from_user_id;
}
int Question::GetIdTo() const {
    return to_user_id;
}
int Question::GetQuestionId() const {
    return question_id;
}
string Question::GetQuestionText() const {
    return question_text;
}
string Question::GetAnswerText() const {
    return answer_text;
}

void Question::SetIdFrom(const int &IdFrom) {
    this->from_user_id = IdFrom;
}
void Question::SetIdTo(const int &IdTo) {
    this->to_user_id = IdTo;
}
void Question::SetQuestionId(const int &question_id) {
    this->question_id = question_id;
}
void Question::SetQuestionText(const string &question_text) {
    this->question_text = question_text;
}
void Question::SetAnswerText(const string &answer_text) {
    this->answer_text = answer_text;
}

void Question::SetParentQuestionId(const int &id) {
    this->parent_question_id = id;
}
int Question::GetParentQuestionId() const {
    return parent_question_id;
}
void Question::SetAnonymousQuestion(const int &anonymous) {
    this->is_anonymous_questions = anonymous;
}
int Question::GetAnonymous() const {
    return is_anonymous_questions;
}
void Question::PrintQuestion(const int &FromOrTo) const {
    if(GetParentQuestionId() != -1){
        cout << "\tThread: ";
    }
    cout << "Question id (" << GetQuestionId() << ") ";
    if(FromOrTo != 1) {
        cout << "From ";
        if (GetAnonymous()) {
            cout << "!AQ ";
        } else {
            cout << "user id (" << from_user_id << ") ";
        }
    }
    if(FromOrTo != 2){
        cout << "To user id (" << GetIdTo() << "):";
    }
    cout << "\nQuestion : " << GetQuestionText() << "\t";
    if(GetAnswerText() != ""){
        cout << "Answer : " << GetAnswerText();
    }
    cout << "\n";
}
string Question::ToString() const {
    ostringstream oss;
    oss << question_id << "," << parent_question_id << "," << from_user_id << "," << to_user_id << ",";
    oss << is_anonymous_questions << "," << question_text << "," << answer_text;
    return oss.str();
}