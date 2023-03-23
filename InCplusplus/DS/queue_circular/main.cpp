#include <iostream>

using namespace std;

const int Max_size = 1000;

template<class t>

class queu {

private:
    t q[Max_size];
    int head , tail , counter;

public:
    queu () {
        head = 0 ;
        tail = -1;
        counter = 0 ;
    }

    bool isempty() {
        return counter == 0 ;
    }

    bool full() {
        return counter == Max_size ;
    }


    void enqueue(t element) {
        if (full())
            cout << "The queue is full.";
        else {
            tail = ((++tail)% Max_size);
            q[tail] = element;
            ++counter ;
        }
    }

    void dequeue() {
        if(isempty())
            cout << "The queue is empty.";
        else {
            head = ((++head)%Max_size);
            --counter ;
        }
    }
    void dequeue(t &element) {
        if(isempty())
            cout << "The queue is empty.";
        else {
            element = q[head];
            head = ((++head)%Max_size);
            --counter ;

        }
    }

    void get_front(t &element) {
        if(isempty())
            cout << "The queue is empty.";
        else {
            element = q[head];
        }
    }

    void get_rear(t &element) {
        if(isempty())
            cout << "The queue is empty.";
        else {
            element = q[tail];
        }
    }

    int q_size() {
        return counter ;
    }

    void q_clear(){
        if(!isempty())
            for (int i = 0 ; i < counter ; i++)
                q[((head+i)%Max_size)] = 0 ;
        head = 0 ;
        tail = -1 ;
        counter = 0 ;
    }

    void print() {
        cout << "[";
        for (int i = 0 ; i < counter ; i++)
            cout << q[((head+i)%Max_size)] << " ";
        cout << "]" << endl ;
    }

    int queue_search (t element) {
        int pos = -1 ;
        if (!isempty()){
            for (int i = 0 ; i < counter ; i++){
                if (q[((head + i )% Max_size)] == element){
                    pos = ((head + i )% Max_size);
                    break ;
                }
            }
        }
        else
            cout << "the queue is empty.";
        return pos;
    }


};

int main()
{
    queu<int> tasks ;
    tasks.enqueue(1);
    tasks.enqueue(11);
    tasks.enqueue(12);
    tasks.enqueue(13);
    tasks.enqueue(41);
    tasks.enqueue(15);
    tasks.print();
    int x , y ;
    tasks.get_front(x);
    tasks.get_rear(y);
    cout << x << " " << y << endl;
    tasks.dequeue();
    tasks.print();
    tasks.q_clear();
    tasks.print();

    return 0;
}
