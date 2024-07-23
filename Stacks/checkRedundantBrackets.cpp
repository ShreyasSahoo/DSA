#include<iostream>
#include<stack>
using namespace std;
bool checkRedundantBrackets(string str){
    stack <char> st;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
            st.push(ch);
        }
        else if(ch == ')'){
            if(!st.empty() && st.top() == '(')
            return true;
        }
    }
    return false;
    
}
int main(){
cout<<checkRedundantBrackets("(a+(b))");
return 0;
}