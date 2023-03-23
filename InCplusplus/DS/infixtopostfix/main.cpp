#include <iostream>
#include<string>
#include<stack>

using namespace std;

bool isoperand(char o) {
    if (o >= '0' && o <= '9') return true;
    else if (o >= 'a' && o <= 'z') return true;
    else if (o >= 'A' && o <= 'Z') return true;
    return false;

}

bool isoperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int priority(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2 ;
    else if (c == '^')
        return 3;
}

string infTopost(string inf) {


    stack<char> stk;
    string post = "";


    for (int i = 0 ; i < inf.length() ; i++) {
        if (inf[i] == ' ' || inf[i] == ',') continue;


        else if (isoperand(inf[i]))
            post += inf[i];


        else if (isoperator(inf[i])){
            while (!stk.empty() && stk.top() != '(' && priority(inf[i]) <= priority(stk.top())) {
                    post += stk.top();
                    stk.pop();
                   }
                   stk.push(inf[i]);
        }

        else if (inf[i] == '(')
                stk.push(inf[i]);

        else if (inf[i]==')'){
            while(!stk.empty() && stk.top()!='('){
                    post += stk.top();
                    stk.pop();
                  }
                  stk.pop();
        }
    }
    while(!stk.empty()){
        post += stk.top();
        stk.pop();
    }
    return post;
}

int calc(int a , int b , char c){
    if (c == '+') return b + a ;
    else if (c == '-') return b - a ;
    else if (c == '*') return b * a ;
    else if (c == '/') return b / a ;
    else return b ^ a ;
}

int summation (string post) {

    stack<int> s;
    for (int i = 0 ; i < post.length() ; i++) {
        if (isoperand(post[i]))
            s.push(int(post[i]-'0'));
        else if (isoperator(post[i])){
            int temp1 = s.top();
            s.pop();
            int temp2 = s.top();
            s.pop();
            s.push(calc(temp1,temp2,post[i]));
        }
    }
    int sm = s.top();
        s.pop();
        return sm;
}

int main()
{
    string expression ;
    cout << "Enter the infex expression ......" << endl;
    getline(cin, expression);
    string postfix = infTopost(expression);
    cout << postfix << endl;
    cout << summation(postfix);
    return 0;
}
