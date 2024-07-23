#include<iostream>
#include<string.h>
using namespace std;
string reverseAString(string s, int left, int right){
    if(left>right)
    return s;
    swap(s[left],s[right]);
    return reverseAString(s,left+1,right-1);
}
int main(){
string str = "hello"; 
cout<<reverseAString(str,0,str.size()-1);
return 0;
}