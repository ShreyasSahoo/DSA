#include<iostream>
using namespace std;
 void addStringsHelper(string num1, string num2,int index1 , int index2, string & ans, int carry){
        if(index1<0 && index2<0 && carry==0) return ;
        int n1,n2;
        if(index1<0) n1 = 0;
        else {
            n1 = (int)num1[index1] - 48;
        }
        if(index2<0) n2 = 0;
        else {
            n2 = (int)num2[index2] - 48;
        }
        cout<<"n1 - "<<n1<<endl;
        cout<<"n2 - "<<n2<<endl;
        int k = n1 + n2 + carry ;
        carry = k/10;
        k = k%10;
        char ch = k + '0';
         cout<<"k - "<<k<<endl;
         cout<<"ch - "<<ch<<endl;
        cout<<"carry - "<<carry<<endl;
         cout<<"----------------------"<<endl;
        ans.insert(ans.begin(),ch);
        addStringsHelper(num1,num2,index1-1,index2-1,ans,carry);
    }
    string addStrings(string num1, string num2) {
        int index1 = num1.size() -1 ;
        int index2 = num2.size() -1 ;
        string ans = "";
        int carry = 0;
        addStringsHelper(num1,num2,index1,index2,ans,carry);
        return ans;
    }
int main(){
    string h = addStrings("123","95");
    cout<<h;
return 0;
}