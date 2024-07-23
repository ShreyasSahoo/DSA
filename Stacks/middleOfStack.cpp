#include<iostream>
#include<stack>
using namespace std;

void midddleOfStackHelper(stack<int> &st,int mid,int &ans){
    if(mid == 1) {
        ans =  st.top();
        return;
    }

    int temp = st.top();
    st.pop();
    midddleOfStackHelper(st,mid-1,ans);
    st.push(temp);//backtracking

}
float lengthOfStack(stack<int> st){
    float length = 0;
    while(!st.empty()){
        st.pop();
        length++;
    }

    return length;
}
int midddleOfStack(stack<int> &st){
    float length = lengthOfStack(st);
    int mid = ceil(length/2);
    int ans;
     midddleOfStackHelper(st,mid,ans);
     return ans;
}
int main(){
stack<int> st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);
st.push(60);
cout<<midddleOfStack(st);
cout<<endl<<st.top();
return 0;
}