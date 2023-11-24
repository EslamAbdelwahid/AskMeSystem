//
// Created by eslam on 11/25/2023.
//

#ifndef ASKME_SYSTEM_QUESTIONSMANAGER_H
#define ASKME_SYSTEM_QUESTIONSMANAGER_H
#include <bits/stdc++.h>
#include "Question.h"
#include "HelperFunctions.h"
#include "User.h"

using namespace std;
class QuestionsManager {
private:
    map < int , vector<int> > idquestion_idthread;
    map < int , Question > GetQuestionUsingId;
    int last_id;
    HelperFunctions helperFunctions;
public:
    void LoadDataBase();
    void ReadQuestion(const int &id_from, const int &id_to, const int &IsAnonymous);
    void UpdateDataBase();
    pair<vector<int> , map<int , vector<int> > > ResetQuestionsFrom_To(const User &current_user);
    void PrintQuestionsFromUser(const User &user) ;
    void PrintQuestionsToUser(const User &user) ;
    void DeleteQuestion();
    void AnswerQuestion(const int &user_id);
    void ListOfQuestions() ;
};

#endif //ASKME_SYSTEM_QUESTIONSMANAGER_H
