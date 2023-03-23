#include <iostream>

using namespace std;

void swapp (int* a , int* b){
    int temp = *a ;
    *a = *b ;
    *b = temp;
}

void BubbleSort(int* ar ,int mx){
    bool flag;
    int counter = 0 ;
    for (int i = 0 ; i < mx ; i++){
        flag = true ;
        for (int j = 0 ; j < mx-i-1 ; j++){
            if (ar[j]>ar[j+1]){
                swapp(&ar[j],&ar[j+1]);
                flag = false ;
            }
        counter++;
        }
        if (flag)
            break ;
    }
//    cout << flag << " " << counter ;
}

void input_size (int* n){
    cout << "Enter array size : ";
    cin >> *n ;
}

void input (int* n , int* ar){
    for (int i = 0 ; i < *n ; i++){
        cout << "Enter the "<< i << " element : ";
        cin >> ar[i];
    }
}

void print (int* n , int* ar){
    cout << "[" ;
    for (int i = 0 ; i < *n-1 ; i++)
        cout << ar[i] << " , ";
    cout << ar[*n-1] << "]";
}

int main()
{
    int Max_size;
    input_size(&Max_size);
    int* arr = new int[Max_size];
    input(&Max_size,arr);
    BubbleSort(arr,Max_size);
    print(&Max_size,arr);
    return 0;
}
