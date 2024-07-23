#include<iostream>
#include<vector>
using namespace std;
void printSubArrays(vector<int> nums,int index,vector<int> output){
    if(index == nums.size()){
        
        for(auto it: output)
        {
            cout<<"->"<<it<<" ";
        }
        cout<<endl;
        return;
    }
    int num = nums[index];
    //exclude
     printSubArrays(nums,index+1,output);
    //include
    output.push_back(num);
     printSubArrays(nums,index+1,output);
}
int main(){
    vector<int> arr ;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
vector<int> output ;
printSubArrays(arr,0,output);
return 0;
}