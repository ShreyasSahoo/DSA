#include<iostream>
using namespace std;
class TwoStacks{
    public:
    int top1,top2,size;
    int * arr;
    TwoStacks(int size){
        arr = new int[size];
        top1 = -1,top2 = size,this->size = size;
    }
    void push1(int element){
        if(top2-top1 == 1){
            cout<<"Stack is full"<<endl;
        }
        arr[++top1] == element;
    }
    void push2(int element){
        if(top2-top1 == 1)
        cout<<"Stack is full"<<endl;
        arr[--top2] == element;
    }
    void pop1(){
        if(top1 == -1)
        cout<<"Stack 1 is empty"<<endl;
        top1--;
    }
    void pop2(){
        if(top2 == this->size)
        cout<<"Stack 1 is empty"<<endl;
        top2++;
    }
};
int main(){
    
return 0;
}