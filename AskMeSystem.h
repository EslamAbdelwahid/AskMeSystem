//
// Created by eslam on 11/25/2023.
//

#ifndef ASKME_SYSTEM_ASKMESYSTEM_H
#define ASKME_SYSTEM_ASKMESYSTEM_H


#include <bits/stdc++.h>
#include "UsersManager.h"
#include "HelperFunctions.h"
#include "QuestionsManager.h"

class AskMeSystem {
private:
    UsersManager usersManager;
    QuestionsManager questionsManager;
    HelperFunctions helperFunctions;
    vector<string>choices;
    void GetCurrentUserQuestions();
    vector<int>id_from;
    map < int , vector<int> > id_to;
public:
    void Run();
    void ResetCurrentUserQuestions();
};


#endif //ASKME_SYSTEM_ASKMESYSTEM_H
