#include<iostream>
using namespace std;
bool isSorted(int arr[],int size,int index){
    if(index == 0){
        return true;
    }
    if(arr[index]>arr[index - 1]){
        return isSorted(arr,size,index-1);
    }
    else{
        return false;
    }
}
int main(){
int arr[]={1,2,3,4,5,0};
int size = 6;
cout<<isSorted(arr,size,size-1);
return 0;
}