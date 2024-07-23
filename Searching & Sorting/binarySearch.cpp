#include<iostream>
using namespace std;
int binarySearch(int nums[], int size, int target){
int start = 0, end = size - 1;
while(start<end){
    int mid = start + (end - start)/2;
    if(nums[mid]==target)
    return mid;
    else if (nums[mid]>target)
    end = mid -1;
    else
    start = mid + 1;
}
return -1;
}
int main(){
    int arr[] = {12,23,45,65,78,112,211,432};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<size;
    cout<<binarySearch(arr,size,23);
return 0;
}