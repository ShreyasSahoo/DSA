#include<iostream>
#include<queue>
using namespace std;
int kthSmallestElement(int arr[],int size,int k){
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for(int i = k;i<size;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){

return 0;
}