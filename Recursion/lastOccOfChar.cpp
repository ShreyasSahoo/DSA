#include<iostream>
#include<string.h>
using namespace std;
int lastOcc(string s,char ch,int i,int lastIndex){
    if(i<0){
        return lastIndex;
    }
    if(s[i]==ch)
    return i;
    else{
      return lastOcc(s,ch,i-1,lastIndex);
    }

}
int main(){
    char str[] = "asbdslfskj";
    char ch = 'l';
cout<<lastOcc(str,'s',9,-1);
char* chPtr;
chPtr = strchr(str,ch);
cout<<endl<<chPtr;
return 0;
}