#include<iostream>
using namespace std;
int divide(int a, int b){
    if(b==0)
    return 0;
    int absOfA = abs(a);
    int absOfB = abs(b);
    int start = 1, end = absOfA;
    int mid = start + (end-start)/2;
    int ans;
    while(start<=end){
        if(mid*absOfB == absOfA){
        ans =  mid;
        break;
        }
        else if( mid*absOfB < absOfA){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    if((a>0 && b<0) || (b>0 && a<0)){
        ans = 0 -ans;
    }
    return ans;
}
int main(){
cout<<divide(-29,3);
return 0;
}