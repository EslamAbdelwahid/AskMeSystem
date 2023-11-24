#include "User.h"
using namespace std;
User::User() : name(""),password(""),user_id(-1),email(""),user_name(""),anonymous_question(-1) {

}
User::User(string &line) {
    auto spilt_string = helperFunctions.SpiltString(line);
    int id = helperFunctions.ToInt(spilt_string[0]);
    int anonymous = helperFunctions.ToInt(spilt_string[5]);
    SetId(id);
    SetUserName(spilt_string[1]);
    SetPassword(spilt_string[2]);
    SetName(spilt_string[3]);
    SetEmail(spilt_string[4]);
    SetAnonymousQuestion(anonymous);
}
// getters
string User::GetEmail() const {
    return email;
}
string User::GetUserName() const {
    return user_name;
}
string User::GetPassword() const {
    return password;
}
string User::GetName() const {
    return name;
}
int User::GetId() const {
    return user_id;
}
int User::IsAnonymousQuestion() const {
    return anonymous_question;
}

// setters
void User::SetEmail(const string &email) {
    this->email = email;
}
void User::SetUserName(const string &username) {
    user_name = username;
}
void User::SetPassword(const string &password) {
    this->password = password;
}
void User::SetName(const string &name) {
    this->name = name;
}
void User::SetId(const int &name_id) {
    this->user_id = name_id;
}
void User::SetAnonymousQuestion(int anonymous_question) {
    this->anonymous_question = anonymous_question;
}

// functions
void User::SetInfo() {
    cout << "Enter user name. (No spaces):";
    cin >> this->user_name;
    cout << "\nEnter password:";
    cin >> this->password;
    cout << "\nEnter email:";
    cin >> this->email;
    cout << "\nEnter your name:";
    cin >> this->name;
    cout << "\nAllow anonymous questions?:(0 or 1)";
    cin >> this->anonymous_question;
    cout << "\n";
}
string User::ToString() {
    ostringstream oss;
    oss << user_id << "," << user_name << "," << password << "," << name << "," << email << "," << anonymous_question;
    return oss.str();
}

void User::SetIdFrom(const vector<int> &id_from) {
    id_questions_from_me.clear();
    for(auto &i : id_from){
        id_questions_from_me.push_back(i);
    }
}
void User::SetIdTo(const map<int, vector<int>> &id_to) {
    QuestionId_QuestionThread.clear();
    for(auto &[l , r] : id_to){
        QuestionId_QuestionThread[l] = r;
    }
}
vector<int> User::GetIdQuestionsFromMe() const {
    return id_questions_from_me;
}
map<int, vector<int> > User::GetIdQuestionsToMe() const {
    return QuestionId_QuestionThread;
}
void User::PrintInfo() const {
    cout << "ID:" << GetId() << "\t" << "Name:" << GetName() << "\n";
}