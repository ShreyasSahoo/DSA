#include<iostream>
using namespace std;

 void selection_sort(int arr[], int size){

    for(int i = 0;i < size - 1;i++){
        int mini = i;
            for(int j = i;j < size ;j++){
                if (arr[j] < arr[mini]) mini = j;
            }
            int temp = arr[mini];
            arr[mini]  = arr[i];
            arr[i]  = temp;
            cout<<"after step "<<i<<" -> ";
            for(int k = 0;k<size;k++) cout<<arr[k]<<" ";
            cout<<endl;
    }

 }

int main(){
    int n;
     cin>>n;
     int arr[n];
     for(int i =0;i<n;i++) cin>>arr[i];
     selection_sort(arr,n);
    //  for(int i =0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}