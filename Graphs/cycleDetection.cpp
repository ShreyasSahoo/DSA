#include<iostream>
#include<queue>
#include<list>
using namespace std;
template<typename T>
class Graph{
public:
unordered_map<T , list<T> > adjList;
void printAdjList(){
    for (auto i : adjList)
    {
        T u = i.first;
        list<T> neighbours = i.second;
        cout<<u<<" -> { ";
       for(auto neighbour: neighbours){
            cout<<neighbour<<", ";
       }
       cout<<"}"<<endl;
    }
       cout<<"--------------"<<endl;
    
}
void addEdge(T start,T end, bool isDirected){
    if(isDirected){
        adjList[start].push_back(end);
    }
    else{
        adjList[start].push_back(end);
        adjList[end].push_back(start);
    }
    // printAdjList();
}

void bfs(T src){
   unordered_map<T,bool> visited;
   queue<T> q;
   q.push(src);
   visited[src] = true;
   while(!q.empty()){
    T frontNode = q.front();
    q.pop();
    cout<<" "<<frontNode;
    for(auto neighbour : adjList[frontNode]){
        if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour] = true;
        }
    }
   }
}

// void dfs(T src,unordered_map<T,bool> &visited){
//     if(!visited[src]){
//         cout<<src<<" ";
//         visited[src] = true;
//     }
    
//     for(auto neighbour : adjList[src]){
//         dfs(neighbour,visited);
//     }
//    }
void dfs(T src, unordered_map<T,bool>& vis ) {
      vis[src] = true;
      cout << src << " ";

      for(auto nbr: adjList[src]) {
       
        if(!vis[nbr]) {
          dfs(nbr, vis);
        }
      }
    }
bool detectCycle(T src){
    unordered_map<T,bool> visited;
    unordered_map<T,T> parent;
    queue<T> q;
    q.push(src);
    parent[src] = '0';
    visited[src] = true;
    while (!q.empty())
    {
        T front = q.front();
        q.pop();
        for(auto child : adjList[front]){
            if(visited[child] && parent[child] != fr ont) return true;
            q.push(child);
            visited[child] = true;
            parent[child] = front;
        }
    }
    return false;
    
}
};
int main(){
    Graph<char> G;
G.addEdge('a','b',0);
G.addEdge('a','c',0);
G.addEdge('b','d',0);
G.addEdge('b','c',0);
G.addEdge('c','e',0);
G.addEdge('c','f',0);
G.addEdge('e','f',0);
cout<<G.detectCycle('a');
return 0;
}