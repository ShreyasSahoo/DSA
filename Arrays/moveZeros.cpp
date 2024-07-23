#include <iostream>
#include <vector>
using namespace std;
 void moveZeroes(vector<int>& nums) {
       int currentIndex,swapIndex = 0;
       for(;currentIndex<nums.size();currentIndex++){
           if(nums[currentIndex]!=0){
               int temp = nums[currentIndex];
              nums[currentIndex]= nums[swapIndex];
              nums[swapIndex] = temp;
               swapIndex++;
           }
       }
    }
int main(){
    vector<int> v ;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(12);

    moveZeroes(v);
    for(auto it : v){
        cout<< it <<endl;
    }
    return 0;
}