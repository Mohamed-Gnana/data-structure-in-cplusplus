#include <iostream>

using namespace std;

template<class t>

class Linked_stack {

private:

    struct Node {

        t item;
        Node *next;

    };

    Node *top;

public:

    Linked_stack() {
        top = NULL;
    }

    void push(t element){

        Node *newitemptr = new Node;
        newitemptr->item = element;
        newitemptr->next = top ;
        top = newitemptr;

    }
    bool isempty(){
        return top == NULL;
    }
    void pop(){
        if (!isempty()){
            Node *temp = top ;
            top = top->next;
            temp->next = NULL;
        }
    }
    void pop(t &element){
        if (!isempty()){
            Node *temp = top;
            element = top->item;
            top = top->next;
            temp->next = NULL;
        }
    }
    void get_top(t &element){
        element = top->item;
    }
    void print(){
        cout << "[";
        Node *ptr ;
        ptr = top ;
        while (ptr!=NULL){
            cout << ptr->item << " ";
            ptr = ptr->next;
        }
        cout << "]";
        cout << endl;
    }


};

int main()
{

    Linked_stack<int> s ;
    s.push(5);
    s.push(15);
    s.push(51);
    s.push(52);
    int y ;
    s.push(25);
    s.pop(y);
    s.print();
    cout<<y;
    return 0;
}
