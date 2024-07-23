#include<iostream>
using namespace std;
void printArr(int arr[],int size,int index){
    if(index == size)
    return;
    cout<<arr[index]<<endl;
    return printArr(arr,size,index+1);
}
bool searchArr(int arr[],int size,int index,int target){
    if(index == size)
    return false;
    if(arr[index] == target)
    return true;
   
    return searchArr(arr,size,index+1,target);
}
void printDigitals(int n){
    if(n==0)
    return ;
    printDigitals(n/10);
    cout<<n%10<<endl;
}
int main(){
    int arr[]= {1,2,3,4,5};
// printArr(arr,5,0);
// cout<<searchArr(arr,5,0,4);
printDigitals(112354);
return 0;
}