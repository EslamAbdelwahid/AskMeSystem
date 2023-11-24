
#include "HelperFunctions.h"
using namespace std;

int HelperFunctions::GetChoice(int l , int r){
    cout << "Enter number in range " << l << " - " << r << ":";
    int choice ; cin >> choice;
    if(choice >= l && choice <= r) return choice;
    cout <<  "Invalid number, Try Again\n";
    return GetChoice(l , r);
}

int HelperFunctions::ShowMenu(const vector<string> &choices){
    cout << "Menu:\n";
    for(int ch = 0;ch < choices.size();++ch){
        cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
    }
    return GetChoice(1,(int)choices.size());
}

vector<string > HelperFunctions::ReadFileLines(string &path) {
    fstream file(path.c_str());
    vector<string>lines;
    if(file.fail()){
        cout << "Can't open the file\n";
        return lines;
    }
    string line;
    while (getline(file , line)){
        if(line.size() == 0) continue;
        lines.push_back(line);
    }
    file.close();
    return lines;
}
void HelperFunctions::WriteFileLines(string &path, vector<string> &lines,bool append) {
    auto states = ios::in | ios::out | ios::app;
    if(!append) states = ios::in | ios::out | ios::trunc;
    fstream file(path.c_str(), states);
    if(file.fail()){
        cout << "Can't open the file\n";
        return;
    }
    for(auto &line : lines){
        file << line << "\n";
    }
    file.close();
}

vector<string> HelperFunctions::SpiltString(string &str) {
    string s = str ,delimiter  = ",";
    vector<string> strs;
    int pos = 0;
    string substr;
    while ((pos = (int) s.find(delimiter)) != -1) {
        substr = s.substr(0, pos);
        strs.push_back(substr);
        s.erase(0, pos + delimiter.length());
    }
    strs.push_back(s);
    return strs;
}
int HelperFunctions::ToInt(string &str) {
    istringstream iss(str);
    int ans;
    iss>>ans;
    return ans;
}