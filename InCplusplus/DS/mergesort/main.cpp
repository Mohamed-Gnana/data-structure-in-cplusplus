#include <iostream>

using namespace std;

void Merge(int l ,int M, int r , int* ar){
    int i , j , k;
    int n1 = M-l+1;
    int n2 = r-M ;
    int *L = new int[n1] , *R = new int[n2];

    for(int m = 0 ; m < n1 ; m++)
        L[m] = ar[l+m];
    for (int m = 0 ; m < n2 ; m++)
        R[m] = ar[M+m+1];

    i = j = 0 ;
    k = l ;

    while (i<n1 && j <n2){
        if (L[i] <= R[j]){
            ar[k] = L[i];
            i++;
        }else {
            ar[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        ar[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        ar[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int l , int r , int* ar){
    if (r<=l)
        return ;
    int M = l + (r-l)/2 ;
    mergesort(l,M,ar);
    mergesort(M+1,r,ar);
    Merge(l,M,r,ar);
}

void MergeSort(int* ar ,int mx){
    mergesort(0,mx-1,ar);
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
    MergeSort(arr,Max_size);
    print(&Max_size,arr);
    return 0;
}
