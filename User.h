//
// Created by eslam on 11/25/2023.
//

#ifndef ASKME_SYSTEM_USER_H
#define ASKME_SYSTEM_USER_H

#include <bits/stdc++.h>
#include "HelperFunctions.h"
using namespace std;
class User{
private:
    string name;
    string password;
    string email;
    string user_name;
    int anonymous_question;
    int user_id;
    HelperFunctions helperFunctions;
    vector<int> id_questions_from_me;
    map < int , vector<int> > QuestionId_QuestionThread;

public:
    User();
    User(string &line);
    // getters
    string GetEmail() const;
    string GetUserName() const;
    string GetPassword() const;
    string GetName() const;
    int GetId() const;
    int IsAnonymousQuestion() const;

    // setters
    void SetEmail(const string &email);
    void SetUserName(const string &user_name);
    void SetPassword(const string &password);
    void SetName(const string &name);
    void SetId(const int &user_id);
    void SetAnonymousQuestion(int anonymous_question);
    // functions
    void SetInfo();
    string ToString();
    void SetIdFrom(const vector<int> &id_from);
    void SetIdTo(const map <int, vector<int>> &id_to);
    vector<int> GetIdQuestionsFromMe() const;
    map < int , vector<int> > GetIdQuestionsToMe() const;
    void PrintInfo() const;

};


#endif //ASKME_SYSTEM_USER_H
