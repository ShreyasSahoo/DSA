#include<iostream>

#include<queue>
using namespace std;
int main(){
priority_queue<int> pq;//max heap by default
pq.push(10);
pq.push(20);
pq.push(30);
cout<<"Top of the Priority Queue "<<pq.top()<<endl<<"Size of the Priority Queue "<<pq.size()<<endl;
pq.pop();
cout<<"Top of the Priority Queue "<<pq.top()<<endl<<"Size of the Priority Queue "<<pq.size()<<endl;
priority_queue<int,vector<int>,greater<int> >minHeap;
cout<<"min Heap"<<endl;
minHeap.push(10);
minHeap.push(0);
minHeap.push(20);
cout<<minHeap.top();
minHeap.pop();
cout<<minHeap.top();
return 0;
}