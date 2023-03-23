#include <iostream>
#include<string>
#include<stack>

using namespace std;

bool arepairs(char a , char b) {
    if (a == '[' && b == ']')
        return true;
    else if (b == '}' && a == '{')
        return true;
    else if (b == ')' && a == '(')
        return true;
    return false;
}

bool chksentence(string s){

    stack<char> stk;
    char *chk ;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i]=='[' || s[i] == '{' || s[i] == '(')
            stk.push(s[i]);
        else if (s[i] == ']' || s[i] == '}' || s[i] == ')'){
            if (stk.empty()|| !arepairs(stk.top(),s[i]))
                return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int main()
{

    string s ;
    cin >> s;
    if(chksentence(s))
        cout << "the sentence is balanced.";
    else
        cout << "the sentence is unbalanced.";
    return 0;
}
