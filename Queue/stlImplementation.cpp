#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue <int> q;
    //insertion
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    // deletion
    q.pop();
    cout<<q.front();
return 0;
}