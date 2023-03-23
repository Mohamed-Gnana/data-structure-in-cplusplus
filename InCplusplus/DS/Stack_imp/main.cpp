#include <iostream>

using namespace std;

#define ll as long long
#define ar as array

template <class t>
class Stack {

private:
    int top ;
    t a[1000];
public:
    Stack() {
        top = -1 ;
    }
    void push(t element) {
        if (top >= 999){
            cout << "The stack is full";
        }
        else {
            top++;
            a[top] = element ;
    }}
    bool isempty(){
        return top < 0 ;
    }
    void pop(){
        if (isempty()){
            cout << "the stack is empty";
        }
        else {
            top--;
        }
    }
    void pop(t &element){
        if (isempty()){
            cout << "the stack is empty";
        }
        else {
            element = a[top];
            top--;
        }
    }
    void get_top(t &stack_top){
        if (isempty()){
            cout << "the stack is empty";
        }
        else {
            stack_top = a[top];
            cout << stack_top;
        }
    }
    void print() {
    cout <<"[";
    for (int i = top ; i >= 0 ; i--){
        cout << a[i] << " ";
    }
    cout << "]";
    cout << endl;
    }


};

int main()
{
    Stack<string>s;
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    s.push("ahmed");
    int y;
    s.print();
    return 0;
}
