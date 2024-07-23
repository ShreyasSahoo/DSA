#include<iostream>
using namespace std;
void merge(int arr[],int start, int end){
    int mid = start + (end-start)/2;
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int *leftArr = new int[leftLength];
    int *rightArr = new int[rightLength];
    int k = start;
    for (int i = 0; i < leftLength; i++)
    {
       leftArr[i]=arr[k++];
    }
    for (int i = 0; i < rightLength; i++)
    {
        rightArr[i]=arr[k++];
    }

    int left= 0,right=0,index=start;
    while(left<leftLength && right<rightLength){
        if(leftArr[left]<rightArr[right]){
            arr[index++]=leftArr[left++];
        }
        else if(leftArr[left]==rightArr[right]){
            arr[index++]=leftArr[left++];
            arr[index++]=rightArr[right++];
        }
        else{
             arr[index++]=rightArr[right++];
        }
    }
    while(left<leftLength){
        arr[index++]= leftArr[left++];
    }
    while(right<rightLength){
        arr[index++]= rightArr[right++];
    }
    delete[] leftArr;
    delete[] rightArr;
}
void mergeSort(int arr[],int start, int end){
    if(start >= end) return;

    int mid = start + (end-start)/2;

    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);

    merge(arr,start,end);
}
int main(){
int arr[] ={2,1,9,4,6,3};
mergeSort(arr,0,5);
for (auto it : arr)
{
  cout<<it<<endl;
}

return 0;
}