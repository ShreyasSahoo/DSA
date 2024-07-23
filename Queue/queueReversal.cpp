#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int> reversalStack;
        int queueElement,stackElement;
        while(!q.empty()){
          queueElement = q.front();
          q.pop();
          reversalStack.push(queueElement);
        }
        while(!reversalStack.empty()){
            stackElement = reversalStack.top();
            reversalStack.pop();
            q.push(stackElement);
        }
        return q;
    }
int main(){

return 0;
}