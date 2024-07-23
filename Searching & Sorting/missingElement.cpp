#include<iostream>
#include<vector>
using namespace std;
int missingElement(vector<int> &arr){
int result = -1 ;
    int start = 0, end = arr.size();
    while (start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]== mid+1){
            start = mid + 1;
        }
        else{
            result = arr[mid] - 1;
            end = mid - 1;
        }
    }
    return result;
}
int main(){
    vector<int> arr ;
    
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    
    cout<<missingElement(arr);
    
    return 0;
}