

#include<iostream>
using namespace std;

 void insertion_sort(int arr[], int size){

    for(int i = 1;i < size;i++){
       int j = i;
       while(arr[j] < arr[j-1] && j > 0){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
       }
       
    }

 }

int main(){
    int n;
     cin>>n;
     int arr[n];
     for(int i =0;i<n;i++) cin>>arr[i];
     insertion_sort(arr,n);
     for(int i =0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}