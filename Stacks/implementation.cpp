#include<iostream>
using namespace std;
class Stack{
    public:
    int size;
    int *arr ;
    int top;
    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    int getTop(){
        if(isEmpty()) {
           cout<<"Stack is empty"<<endl;
           return INT_MIN;
        }
        return arr[top];
    }
    void push(int data){
        if(top+1>this->size){
            cout<<"Overflow"<<endl;
        }
        top++;
        arr[top] = data;
    }
    void pop(){
        if(top==-1){
            cout<<"Underflow"<<endl;
        }
        arr[top] = 0;
        top--;
    }
    bool isEmpty(){
          if(top==-1){
           return true;
            }
        return false;
    }
};
int main(){
Stack st(5);
st.push(10);
st.push(20);
st.push(30);
cout<<st.getTop();
// cout<<st.isEmpty();
st.pop();
cout<<st.getTop();
return 0;
}