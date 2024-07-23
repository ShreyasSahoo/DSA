#include<iostream>
using namespace std;
void printPermutations(string& s,int index){
if(index>=s.length()){
    cout<<s<<endl;
    return;
}
for (int j = index; j < s.length(); j++)
{
    swap(s[index],s[j]);
    printPermutations(s,index+1);
    swap(s[index],s[j]);
}

}
int main(){
string s = "abc";
printPermutations(s,0);
return 0;
}