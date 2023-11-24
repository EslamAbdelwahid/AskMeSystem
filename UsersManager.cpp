#include "UsersManager.h"
using namespace std;
UsersManager ::UsersManager() : last_id(0){
}

void UsersManager::DoLogIn() {
    cout << "Enter username & password\n";
    string name , pass;
    cin >> name >> pass;
    if(username_pass_userobject[{name , pass}].GetUserName() == ""){
        cout << "Invalid username or password, Try again\n";
        DoLogIn();
    }else{
        current_user = username_pass_userobject[{name , pass}];
    }
}

void UsersManager::DoSignUp(){
    User user;
    user.SetInfo();
    if(username_pass_userobject[{user.GetUserName(),user.GetPassword()}].GetUserName() != ""){
        cout << "This user is exist, Try again\n";
        DoSignUp();
        return;
    }
    user.SetId(++last_id);
    current_user = user;
    username_pass_userobject[{user.GetUserName(),user.GetPassword()}] = user;
    userid_objectuser[user.GetId()] = user;
    string str = user.ToString();
    UpdateDataBase(str);
}

void UsersManager::LoadDataBase() {
    string path = "users.txt";
    username_pass_userobject.clear();
    vector<string> lines = helperFunctions.ReadFileLines(path);
    last_id = 0;
    // assert(lines.size());
    for(auto &line : lines){
        User user(line);
        last_id = max(last_id , user.GetId());
        username_pass_userobject[{user.GetUserName() , user.GetPassword()}] = user;
        userid_objectuser[user.GetId()] = user;
    }
}
void UsersManager::UpdateDataBase(string &line) {
    vector<string > lines = {line};
    string path = "users.txt";
    helperFunctions.WriteFileLines(path , lines , true);
}
User UsersManager::GetCurrentUser() const{
    return current_user;
}
array<int,3> UsersManager::ReadIdUser()  {
    cout << "Enter User id or -1 to cancel:";
    int id;
    cin >> id;
    int anonymous =  userid_objectuser[id].IsAnonymousQuestion();
    return {current_user.GetId() , id, anonymous};
}
void UsersManager::ResetFromQuestions(const vector<int> &questions_ids) {
    current_user.SetIdFrom(questions_ids);
}
void UsersManager::ResetToQuestions(const map<int, vector<int>> &questindid_threadsids) {
    current_user.SetIdTo(questindid_threadsids);
}
void UsersManager::ListOfUsers() {
    for(auto &[id , user] : userid_objectuser){
        user.PrintInfo();
    }
}