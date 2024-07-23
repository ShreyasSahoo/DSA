#include<iostream>
using namespace std;
int peakElement(vector<int>& nums){
    int start=0,end=nums.size()-1;
    int result = -1;
    while (start<=end)
    {
        int mid = start + (end-start)/2;
        if(nums[mid+1]>nums[mid]){
            start=mid+1;
        }
        else{
            result= nums[mid];
            end = mid -1;
        }
    }
    return result;
}
int main(){
    vector<int> v;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);
    v.push_back(30);
    
    cout << peakElement(v);
    return 0;
}