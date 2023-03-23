#include <iostream>

using namespace std;

class doublelinked {

private:
    struct Node {
        int item ;
        Node *next ;
        Node *prev ;
    };
    int length ;
    Node *head ;
    Node *tail ;

public:
    doublelinked () {
        length = 0 ;
        head = tail = NULL ;
    }

    bool isempty () {
        return head == NULL ;
    }

    int getsize () {
        return length ;
    }

    void insertfirst (int element) {
        Node *newitem = new Node ;
        newitem->item = element ;
        if (isempty()){
            newitem->next = NULL ;
            newitem->prev = NULL ;
            head = tail = newitem ;
        }
        else {
            head->prev = newitem ;
            newitem->next = head ;
            newitem->prev = NULL ;
            head = newitem ;
        }
        length ++;
    }

    void insertlast (int element){
        Node *newitem = new Node ;
        newitem->item = element ;
        if (isempty()){
            newitem->next = NULL;
            newitem->prev = NULL ;
            head = tail = newitem;
        }
        else {
            newitem->prev = tail ;
            newitem->next = NULL ;
            tail->next = newitem ;
            tail = newitem ;
        }
        length++;
    }



    void insertat (int pos , int element) {
        if (pos < 0 || pos > length)
            cout << "Out of range.";
        else {
            if (pos == 0)
                insertfirst(element);
            else if (pos == length)
                insertlast(element);
            else {
                Node *newitem = new Node ;
                newitem->item = element ;
                Node *cur = head ;
                Node *prv = NULL ;
                for (int i = 0 ; i < pos ; i++){
                    prv = cur ;
                    cur = cur->next ;
                }
                newitem->next = cur ;
                newitem->prev = prv ;
                cur->prev = newitem ;
                prv->next = newitem ;
                length ++;
            }
        }
    }

    void removefirst () {
        if (isempty())
            cout << "The List is empty .";
        else if (length == 1) {
            delete head ;
            head = tail = NULL ;
            length = 0 ;
        }
        else {
            Node *cur = head ;
            head = head->next ;
            head->prev = NULL ;
            delete cur ;
            length --;
        }
    }

    void removelast () {
        if (isempty())
            cout << "The List is empty .";
        else if (length == 1) {
            delete head ;
            head = tail = NULL ;
            length = 0 ;
        }
        else {
            Node *cur = tail ;
            tail = tail->prev ;
            tail->next = NULL ;
            delete cur ;
            length --;
        }
    }

    void removeat(int element) {
        if (isempty())
            cout << "The List is empty.";
        else {
            if (head->item == element)
                removefirst();
            else if (tail->item == element)
                removelast();
            else {
                Node *cur = head->next ;
                while(cur != tail){
                    if (cur->item == element){
                        break ;
                    }
                    cur = cur->next ;
                }
                if (cur == tail)
                    cout << "Item is not found.";
                else {
                    Node *prv = cur->prev ;
                    Node *nxt = cur->next ;
                    nxt->prev = prv ;
                    prv->next = nxt ;
                    delete cur;
                    length --;
                    }
            }
        }
    }

    void print () {
        cout << "[";
        Node *cur = head ;
        while (cur != NULL){
            cout << cur->item << " ";
            cur = cur->next ;
        }
        cout << "]";
    }

    void reverseprint () {
        cout << "[";
        Node *cur = tail ;
        while (cur != NULL){
            cout << cur->item << " ";
            cur = cur->prev;
        }
        cout << "]";
    }

    ~doublelinked (){
        Node *temp;
        while(head != NULL){
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL ;
        length = 0 ;
    }

};

int main()
{
    doublelinked l ;
    l.insertfirst(3);
    l.insertfirst(13);
    l.insertfirst(23);
    l.insertlast(3);
    l.insertlast(13);
    l.insertlast(23);
    l.print();
    l.reverseprint();
    l.insertat(3,33);
    l.insertat(4,33);
    l.print();
    l.reverseprint();
    l.removefirst();
    l.removelast();
    l.print();
    l.reverseprint();
    l.removeat(13);
    l.print();
    l.reverseprint();
    l.removeat(13);

    return 0;
}
