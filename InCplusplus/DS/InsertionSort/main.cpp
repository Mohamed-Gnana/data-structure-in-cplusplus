#include <iostream>

using namespace std;

void shift_index(int a , int* ar){
    int temp = *(ar+a);
    int i ;
    for (i = a ; (ar[i] >= temp && i >= 0) ; i--){
        ar[i] = ar[i-1];
    }
    ar[i+1] = temp ;
}

void shift (int a , int b , int* ar){
    int temp = *(ar+b) ;
    for (int i = b ; i > a ; i--){
        ar[i]=ar[i-1];
    }
    ar[a] = temp;
}

int index(int a , int* ar){
    int idx = a ;
    for (int i = 0 ; i < a ; i++){
        if(ar[i] >= ar[a]){
            idx = i ;
            break;
        }
    }
    return idx;
}

void InsertionSort(int* ar ,int mx){
    int idx;
    for (int i = 1 ; i < mx ; i++){
//        idx = index(i,ar);
//        shift(idx,i,ar);
        shift_index(i,ar);
    }
}

void input_size (int* n){
    cout << "Enter array size : ";
    cin >> *n ;
}

void input (int* n , int* ar){
    for (int i = 0 ; i < *n ; i++){
        cout << "Enter the "<< i+1 << " element : ";
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
    InsertionSort(arr,Max_size);
    print(&Max_size,arr);
    return 0;
}
