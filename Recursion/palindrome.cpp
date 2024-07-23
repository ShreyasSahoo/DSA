#include<iostream>
using namespace std;
bool isPalindrome(string s,int left,int right){
    if(left>right)
    return true;
    if(s[left]!=s[right])
    return false;
    return isPalindrome(s,left+1,right-1);
}
int main(){
    string str = "namana";
    cout<<isPalindrome(str,0,str.size()-1);
return 0;
}