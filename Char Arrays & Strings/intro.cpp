#include<iostream>
#include<string.h>
using namespace std;
int main(){
string str;
cin>>str;
cout<<str.length()<<endl;
cout<<str.capacity()<<endl;
cout<<str.max_size();
cout<<str;
str.clear();
cout<<str;
return 0;
}