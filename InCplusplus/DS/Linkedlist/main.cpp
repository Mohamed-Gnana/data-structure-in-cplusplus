#include <iostream>

using namespace std;

class linkedlist {

private:
    struct Node {
        int item ;
        Node *next;
    };
    int length ;
    Node *head ;
    Node *tail ;

public:
    linkedlist () {
        length = 0 ;
        head = NULL ;
        tail = NULL ;
    }

    bool isempty() {
        return length == 0 ;
    }

    void insertfromfront(int element) {
        Node *newitem = new Node ;
        newitem->item = element;
        if (isempty()){
            newitem->next = NULL ;
            head = newitem ;
            tail = newitem ;
        }
        else {
            newitem->next = head ;
            head = newitem ;
        }
        length++ ;
    }
    void insertfromend(int element) {
        Node *newitem = new Node ;
        newitem->item = element ;
        if (isempty()){
            newitem->next = NULL ;
            head = newitem ;
            tail = newitem ;
        }
        else {
            tail->next = newitem;
            newitem->next = NULL ;
            tail = newitem ;
        }
        length++ ;
    }

    void insertat (int pos , int element) {
        if (pos == 0)
            insertfromfront(element);
        else if (pos == length)
            insertfromend(element);
        else if (pos < 0 || pos > length)
            cout << "Out of range.";
        else {
            Node *newitem = new Node ;
            newitem->item = element;
            Node *cur = head ;
            int i = 0 ;
            while (i<pos){
                cur = cur->next ;
                i++;
            }
            newitem->next = cur->next;
            cur->next = newitem ;
            length++ ;
        }

    }

    void removefirst () {
        if (isempty()){
            cout << "The List is already empty.";
            return;}
        else if (length == 1){
            delete head ;
            head = tail = NULL ;
        }
        else {
            Node *cur = head ;
            head = head->next ;
            delete cur ;
        }
        length-- ;
    }

    void removeend () {
        if (isempty()){
            cout << "The List is already empty.";
            return;}
        else if (length == 1){
            delete head ;
            head = tail = NULL ;
        }
        else {
            Node *cur = head ;
            Node *prv ;
            while (cur != tail) {
                prv = cur ;
                cur = cur->next;
            }
            delete cur ;
            prv->next = NULL;
            tail = prv;
            }
        length-- ;
    }

    void removeat(int pos) {
        if (pos < 0 || pos > length )
            cout << "Out of range.";
        else {
            if (pos == 0)
                removefirst();
            else if (pos == length)
                removeend();
            else {
                Node *cur = head ;
                Node *prv ;
                for (int i = 0 ; i < pos ; i++){
                    prv = cur ;
                    cur = cur->next ;
                }
                prv->next = cur->next ;
                delete cur ;
                length--;
            }
        }
        }

        void reverselist () {
            if (isempty())
                cout << "The list is empty. ";
            else {
                Node *cur = head ;
                Node *prv = NULL;
                Node *nxt ;
                tail = head ;
                while (cur != NULL){
                    nxt = cur->next;
                    cur->next = prv ;
                    prv = cur ;
                    cur = nxt ;
                }
                head = prv ;
            }
        }

    void reverserec(Node *prv , Node *cur){
        if (cur != NULL){
            reverserec(cur , cur->next);
            cur->next = prv;
            if (cur == tail)
                head = cur ;
            if (prv == NULL)
                tail = cur;
        }
    }

    void reverserecursion () {
        Node *cur = head ;
        Node *prv = NULL ;
        reverserec(prv , cur);
    }

    int searchat (int element) {
        Node *cur ;
        int pos = 0 ;
        while (cur != NULL) {
            if (cur->item == element)
                return pos ;
            cur = cur->next ;
            pos +=1 ;
        }
        return -1;
    }

    void print () {
        cout << "[";
        Node *cur = head ;
        while (cur != NULL){
            cout << cur->item << " ";
            cur = cur->next ;
        }
        cout << "]"<< endl ;
    }
};

int main()
{

    linkedlist l ;
    l.insertat(0,2);
    l.insertfromfront(21);
    l.insertfromfront(23);
    l.insertfromfront(25);
    l.insertfromend(21);
    l.insertfromend(23);
    l.insertfromend(25);
    l.insertat(7,2);
    l.reverserecursion();
    l.print();
    l.reverselist();
    l.removeat(0);
    l.removeat(7);
    l.print();
    l.removefirst();
    l.removefirst();
    l.removefirst();
    l.print();
    l.removeend();
    l.removeend();
    l.removeend();
    l.print();
    return 0;
}
