#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> &arr, int target){
int result = -1 ;
    int start = 0, end = arr.size();
    while (start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==target)
       {
        result = mid;
        end = mid -1;
       }
        else if (arr[mid]>target){
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }
return result;
}
int lastOccurence(vector<int> &arr, int target){
int result = -1 ;
    int start = 0, end = arr.size();
    while (start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==target)
       {
        result = mid;
        start = mid + 1;
       }
        else if (arr[mid]>target){
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
    }
return result;
}
int main() {
    // Your code here
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    cout<<firstOccurence(v,40)<<endl;
    cout<<lastOccurence(v,40)<<endl;
    cout<<"Total number of occurences = lastOcc - firstOcc + 1 i.e "<<(lastOccurence(v,40) - firstOccurence(v,40)) + 1;
    return 0;
}
