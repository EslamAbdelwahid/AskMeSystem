
#ifndef ASKME_SYSTEM_QUESTION_H
#define ASKME_SYSTEM_QUESTION_H

#include <bits/stdc++.h>
#include "HelperFunctions.h"
using namespace std;

class Question {
private:
    int question_id;
    int parent_question_id;
    int from_user_id;
    int to_user_id;
    int is_anonymous_questions;
    string question_text , answer_text;
    HelperFunctions helperFunctions;
public:
    Question();
    Question(vector<string>&str);
    int GetIdFrom()const;
    int GetIdTo() const;
    int GetQuestionId()const;
    string GetQuestionText()const;
    string GetAnswerText()const;
    void SetIdFrom(const int &IdFrom);
    void SetIdTo(const int &IdTo);
    void SetQuestionId(const int &question_id);
    void SetQuestionText(const string &question_text);
    void SetAnswerText(const string &question_answer);
    void SetParentQuestionId(const int &id);
    int GetParentQuestionId()const;
    void SetAnonymousQuestion(const int &anonymous);
    int GetAnonymous()const;
    void PrintQuestion(const int &FromOrTo)const;
    string ToString() const;

};

#endif //ASKME_SYSTEM_QUESTION_H
