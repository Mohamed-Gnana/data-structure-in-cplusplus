#include <iostream>

using namespace std;

class arraylist {

private:
    int *arr ;
    int maxsize ;
    int length ;
public:
    arraylist (int s=10) {
        if (s<0)
            maxsize = 10 ;
        else
            maxsize = s ;
        length = 0 ;
        arr = new int[maxsize] ;
    }

    bool isempty() {
        return length == 0 ;
    }
    bool isfull () {
        return length == maxsize ;
    }
    int getsize () {
        return length ;
    }
    void print () {
        cout << "[";
        for (int i = 0 ; i < length ; i++ ){
            cout << arr[i] << " " ;
        }
        cout << "]" << endl;
    }

    void insertat (int pos , int element){
        if (isfull())
            cout << "the array is full.";
        else if (pos < 0 || pos > length)
            cout << "Out of range." ;
        else {
        for ( int i = length ; i > pos ; i--)
            arr[i] = arr[i-1];
        arr[pos] = element ;
        length++ ;
        }
    }

    void insertatend (int element) {
        if (isfull())
            cout << "The array is full .";
        else {
            arr[length] = element;
            length++;
        }
    }

    int searchat(int element) {
        for (int i = 0 ; i < length ; i++) {
            if (arr[i] == element)
                return i;
        }
        return -1;
    }

    void insertnodup(int element) {
        if(searchat(element)==-1)
            insertatend(element);
        else
            cout << "The element is already in the list.";
    }

    void updateat (int pos , int element) {
        if (pos < 0 || pos > length)
            cout << "out of range.";
        else
            arr[pos] = element ;
    }

    int retelement (int pos) {
        if (pos < 0 || pos > length)
            cout << "out of range.";
        else
            return arr[pos];
    }


    void deleteat (int pos) {
        if (isempty())
            cout << "The array is empty." ;
        else if (pos < 0 || pos > length)
            cout << "Out of range .";
        else {
            for (int i = pos ; i < length; i++)
                arr[i] = arr[i+1];
            length--;
        }
    }


    void clr () {
        length = 0 ;
    }

    ~arraylist () {
        delete []arr ;
    }

};

int main()
{

    arraylist ar(10) ;
    ar.insertatend(3);
    ar.insertatend(13);
    ar.insertatend(31);
    ar.insertatend(32);
    ar.insertatend(23);
    ar.insertat(1,22);
    ar.insertat(4,44);
    ar.print();
    ar.updateat(0,66);
    ar.print();
    cout << ar.searchat(66)<<endl;
    ar.deleteat(0);
    cout << ar.searchat(66)<<endl;
    cout << ar.retelement(0);
    ar.insertnodup(44);
    return 0;
}
