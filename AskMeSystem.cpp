#include "AskMeSystem.h"
using namespace std;

void AskMeSystem::Run() {
    usersManager.LoadDataBase();
    questionsManager.LoadDataBase();
    choices.clear();
    choices = {"LogIn","SignUp"};
    int choice = helperFunctions.ShowMenu(choices);
    if(choice == 1){
        usersManager.DoLogIn();
    }else{
        usersManager.DoSignUp();
    }
    choices.clear();
    choices.push_back("Print Questions To Me");
    choices.push_back("Print Questions From Me");
    choices.push_back("Answer Question");
    choices.push_back("Delete Question");
    choices.push_back("Ask Question");
    choices.push_back("List System Users");
    choices.push_back("Feed");
    choices.push_back("Logout");
    do{
        choice = helperFunctions.ShowMenu(choices);
        ResetCurrentUserQuestions();
        questionsManager.LoadDataBase();
        if(choice == 1){
            const auto &user = usersManager.GetCurrentUser();
            questionsManager.PrintQuestionsToUser(user);
        }else if(choice == 2){
            const auto &user = usersManager.GetCurrentUser();
            questionsManager.PrintQuestionsFromUser(user);
        }else if(choice == 3){
            const auto &user = usersManager.GetCurrentUser();
            questionsManager.AnswerQuestion(user.GetId());
            questionsManager.UpdateDataBase();
        }else if(choice == 4){
            questionsManager.DeleteQuestion();
            questionsManager.UpdateDataBase();
        }else if(choice == 5){
            array<int,3>  id_from_to = usersManager.ReadIdUser();
            if(id_from_to[1] != -1) {
                questionsManager.ReadQuestion(id_from_to[0], id_from_to[1],id_from_to[2]);
                questionsManager.UpdateDataBase();
            }
        }else if(choice == 6){
            usersManager.ListOfUsers();
        }else if(choice == 7){
            questionsManager.ListOfQuestions();
        }
    }while (choice != 8);
    Run();
}

void AskMeSystem::ResetCurrentUserQuestions() {
    const User &user = usersManager.GetCurrentUser();
    const auto &from_to = questionsManager.ResetQuestionsFrom_To(user);
    usersManager.ResetFromQuestions(from_to.first);
    usersManager.ResetToQuestions(from_to.second);
}