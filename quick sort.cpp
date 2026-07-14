
#include <iostream>
using namespace std;

void quickSort(int arr[],int low,int high){
    int L= low;
    int R= high;
    int p= (high+low)/2;
    int pivot=arr[p];
    while(L<R){
        if(arr[L]<arr[p]){
            L++;
        }
        else{
        swap(arr[L],arr[p]);
        p=L;
        }
   
       if(arr[R]>arr[p]){
           R--;
        }
        else{
            swap(arr[R],arr[p]);
            p=R;
        }
        if (L == R) break;
    }

    if (low < p) quickSort(arr, low, p - 1);
    if (p < high) quickSort(arr, p + 1, high);
}


int main() {
   int arr[]={22,92,18,17,11,52,78,66,51,85};
   int size=10;
   quickSort(arr,0,size-1);
   
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
   
    return 0;
}