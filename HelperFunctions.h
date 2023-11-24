
#ifndef ASKME_SYSTEM_HELPERFUNCTIONS_H
#define ASKME_SYSTEM_HELPERFUNCTIONS_H

#include <bits/stdc++.h>
using namespace std;

class HelperFunctions{
public:
    int GetChoice(int l , int r);
    int ShowMenu(const vector<string> &choices);
    vector<string> ReadFileLines(string &path);
    void WriteFileLines(string &path,vector<string > &lines, bool append);
    vector<string> SpiltString(string &str);
    int ToInt(string &str);
};


#endif //ASKME_SYSTEM_HELPERFUNCTIONS_H
