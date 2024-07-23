#include<iostream>
#include<queue>
//interleave first and second half of a queue
using namespace std;
queue<int> rearrangeQueue(queue<int> &q){
        int size = q.size(),q1size;
        queue<int> q1;
        if(size%2==0){
            q1size = size/2;
        }else{
              q1size = (size/2) + 1;
        }
        for(int i =0;i<q1size;i++){
            q1.push(q.front());
            q.pop();
        }
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
            q.push(q.front());
            q.pop();
        }
        return q;
    }
int main(){

return 0;
}