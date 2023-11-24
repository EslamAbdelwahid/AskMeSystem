//
// Created by eslam on 11/25/2023.
//

#ifndef ASKME_SYSTEM_USERSMANAGER_H
#define ASKME_SYSTEM_USERSMANAGER_H

#include <bits/stdc++.h>
#include "User.h"
#include "HelperFunctions.h"
using namespace std;

class UsersManager {
private:
    User current_user;
    HelperFunctions helperFunctions;
    int last_id;
    map < pair<string,string > , User > username_pass_userobject;
    map < int , User > userid_objectuser;
public:
    UsersManager();
    void DoLogIn();
    void DoSignUp();
    void LoadDataBase();
    void UpdateDataBase(string &line);
    User GetCurrentUser() const;
    array<int,3> ReadIdUser() ;
    void ResetFromQuestions(const vector<int> &questions_ids);
    void ResetToQuestions(const map < int , vector<int> > &questindid_threadsids);
    void ListOfUsers();
};



#endif //ASKME_SYSTEM_USERSMANAGER_H
