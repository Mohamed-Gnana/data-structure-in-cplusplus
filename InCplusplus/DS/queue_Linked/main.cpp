#include <iostream>

using namespace std;


template<class t>

class Queue {

private:
    struct Node {
        t item ;
        Node *next ;
    };
    Node *head ;
    Node *tail ;
    int counter;

public:
    Queue () {
        head = NULL ;
        tail = NULL ;
        counter = 0 ;
    }

    bool isempty () {
        return tail == NULL ;
    }

    void enqueue (t element) {
        Node *newitem = new Node ;
        newitem->item = element ;
        newitem->next = NULL ;
        if (isempty()){
            head = newitem;
            tail = head;
        }
        else {
            tail->next = newitem ;
            tail = newitem ;
        }

        counter += 1;
    }

    void dequeue () {
        Node *temp = head ;
        head = head->next ;
        temp->next = NULL;
        counter -= 1;
    }

    void dequeue (t &element) {
        Node *temp = head ;
        element = head->item ;
        head = head->next ;
        temp->next = NULL;
        counter -= 1;
    }
    void get_front (t &element) {
        element = head->item ;
    }

    void get_rear (t &element) {
        element = tail->item ;
    }

    int Q_size () {
        return counter ;
    }

    void Q_clear () {
        while (head != tail){
            Node *temp = head ;
            head = head->next ;
            temp = NULL ;
        }
        head = NULL ;
        tail = NULL ;
        counter = 0 ;
    }

    void print () {
        cout << "[";
        Node *i = head ;
        while (i!=tail) {
            cout << i->item << " " ;
            i = i->next ;
        }
        cout << i->item ;
        cout << "]" ;
    }

    int Q_search(t element){
        int pos = -1 , counterr = 0;
        Node *i = head ;
        while (i!=tail){
            if(element == i->item){
                return counterr ;
            }
            i = i->next ;
            counterr += 1;
        }
        if (tail->item == element)
            return counterr ;
        return pos ;
    }

};

int main()
{
    Queue<int> tasks ;
    tasks.enqueue(1);
    tasks.enqueue(11);
    tasks.enqueue(12);
    tasks.enqueue(21);
    tasks.enqueue(13);
    tasks.print();
    int x , y ;
    tasks.get_front(x) ;
    tasks.get_rear(y);
    cout << x << y ;
    tasks.dequeue() ;
    tasks.print();
    cout << tasks.Q_search(12) ;
    return 0;
}
