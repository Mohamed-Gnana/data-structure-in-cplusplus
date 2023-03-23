#include <iostream>
#include <string>
using namespace std;

// 90 80 50 30 20 15 12
// 55 33 11 44 22
// first : level 2 start with i = 1
// l = 44 , r = 22 , max = 33
// 44 > 33 so swap 44 and 33 >> 55 44 11 33 22 >> and i = 3
// l > n , r > n , max = 33 check maximum
// NO change so end of the first iteration
// second iteration check level 1 with i = 0
// l = 44 , r = 11 , max = 55 check
// 55 is the maximum end of the heap build >> 55 44 11 33 22
//             55
//           44  11
//         33  22
// shift the maximum at the root and rebuild the heap >> 22 44 11 33 55
// first iteration >> 22 44 11 33 55 at level 1
// second iteration at level 0 >> 44 22 11 33 55 and i = 1
// check maximum and swap >> 44 33 11 22 55 and i = 3 end of iteration
// shift the maximum at the root and rebuild the heap tree >> 22 33 11 44 55
//and so on;
//
//

void hepify(int ar[] , int n , int i){
    int l = 2*i + 1 ;
    int r = 2*i + 2 ;
    int mx = i ;

    if (l<n && ar[l]> ar[mx])
        mx = l ;
    if (r < n && ar[r]> ar[mx])
        mx = r ;

    if (mx != i){
        swap(ar[i],ar[mx]);
        hepify(ar , n , mx);
    }
}

void BuildHeap (int* ar ,int n){
    for (int i = n/2 - 1 ; i >= 0 ; i--){
        hepify(ar , n , i);
    }
}

void HeapSort(int* ar , int mx){

    BuildHeap(ar , mx)
    for (int i = mx - 1 ; i >= 0 ; i--){
        swap(ar[i],ar[0]);
        hepify(ar , i , 0);
    }

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
    HeapsortSort(arr,Max_size);
    print(&Max_size,arr);
    return 0;
}
