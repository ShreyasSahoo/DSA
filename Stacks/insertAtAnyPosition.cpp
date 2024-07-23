#include<iostream>
#include<stack>
using namespace std;
int lengthOfStack(stack<int> st){
    int length = 0;
    while(!st.empty()){
        st.pop();
        length++;
    }

    return length;
}
void insertAtAnyPositionHelper(stack<int> &st,int position,int element){
    if(position == 1){
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();
     insertAtAnyPositionHelper(st,position-1,element);
    st.push(temp);
}
void insertAtAnyPosition(stack<int>&st,int position,int element){
    int length = lengthOfStack(st);
    if(position>length+1){
        cout<<"Invalid position"<<endl;
        return;
    }
    insertAtAnyPositionHelper(st,position,element);
}
void printStack(stack<int>st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}
int main(){
    stack<int> st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);
st.push(60);
insertAtAnyPosition(st,4,100);
printStack(st);
return 0;
}