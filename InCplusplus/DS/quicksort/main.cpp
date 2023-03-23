#include <iostream>
#include <stdlib.h>
using namespace std;

void swapp (int* a , int* b){
    int temp = *a ;
    *a = *b ;
    *b = temp;
}

int partitioning (int l , int r , int* ar){
    int* pivot = ar+(rand()%(r-l+1)+l);
    swapp(ar+l,pivot);
    pivot = ar+l;
    int pivot_idx = l ;
    for (int i = l+1 ; i <= r ; i++){
        if (ar[i]<= *pivot){
            pivot_idx++ ;
            swapp(ar+i,ar+pivot_idx);
        }
    }
    swapp(ar+pivot_idx,pivot);
    return pivot_idx;
}

void quicksort(int l , int r , int* ar){
    if (r<=l)
        return ;
    int p = partitioning(l,r,ar);
    quicksort(l,p-1,ar);
    quicksort(p+1,r,ar);
}

void QuickSort(int* ar ,int mx){
    quicksort(0,mx-1,ar);
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
    QuickSort(arr,Max_size);
    print(&Max_size,arr);
    return 0;
}
