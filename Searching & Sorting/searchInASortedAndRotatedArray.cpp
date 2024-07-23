#include<iostream>
#include<vector>
using namespace std;
// int pivotElementIndex(int nums[],int size){
//     int start = 0, end = size -1; 
//     int mid = start + (end - start)/2;


//     while( start<= end){
//         //edge case where there is only one element in the array
//         if(start==end)
//         return start;
//        //pivot element
//         if(mid+1 < size && nums[mid] > nums[mid+1])
//         return mid;
//         //next element to pivot
//         else if(mid - 1 >= 0 && nums[mid-1] > nums[mid])
//         return mid-1;
//         // on line B - move leftwards
//         else if (nums[start] > nums[mid])
//         end = mid - 1;
//         // on line A - move rightwards
//         else 
//         start = mid + 1;
         
//         mid = start + (end - start)/2;
//     }
//     return mid;
// }
 int pivotElementIndex(vector<int>& nums,int size){
    int start = 0, end = size -1; 
    int mid = start + (end - start)/2;

    while( start<= end){
        //edge case where there is only one element in the array
        if(start==end)
        return start;
       //pivot element
        if(mid+1 < size && nums[mid] > nums[mid+1])
        return mid;
        //next element to pivot
        else if(mid - 1 >= 0 && nums[mid-1] > nums[mid])
        return mid-1;
        // on line B - move leftwards
        else if (nums[start] > nums[mid])
        end = mid - 1;
        // on line A - move rightwards
        else 
        start = mid + 1;
         
        mid = start + (end - start)/2;
    }
    return mid;
}
int binarySearch(vector<int>& nums, int target,int start , int end){
    int mid = start + (end-start)/2;
    while(start<=end){
        if(nums[mid]==target)
        return mid;
        else if (nums[mid] > target)
        end = mid -1;
        else
        start = mid + 1; 
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int index = pivotElementIndex(nums,nums.size()); 
        int pivotElement = nums[index];
        int ans = -1;
        if(target <= pivotElement && target >= nums[0]){
            ans = binarySearch(nums,target,0,index);
        }
        else if(index + 1 <= nums.size() - 1 && target >= nums[index+1] && target <= nums[nums.size() - 1]){
           
            ans = binarySearch(nums,target,index+1,nums.size() - 1);
            
        }
        return ans;
    }
int main(){
    int nums[] ={14,16,18,2,4,6,8,10,12};
    int size = sizeof(nums)/sizeof(nums[0]);
    int num[] ={4,5,6,7,0,1,2};
    int pivotIndex = pivotElementIndex(num,7);
    cout<<pivotIndex<< " "<<num[pivotIndex]<<endl;
    return 0;
}