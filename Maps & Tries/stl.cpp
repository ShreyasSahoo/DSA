#include<iostream>
#include<map>
using namespace std;
int main(){
map <char,int> mp;
string s = "shreyassahoo";
for (int i = 0; i < s.length(); i++)
{
    if(mp.find(s[i]) == mp.end()){
        mp[s[i]] = 1;
    }
    else{
        mp[s[i]]++;
    }
}
for (auto i : mp)
{
    cout<<i.first<<" "<<i.second<<endl;
}


return 0;
}