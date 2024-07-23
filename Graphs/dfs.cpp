#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;
template <typename T>
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
};
int main(){
Graph<char> G;
G.addEdge('a','b',1);
G.addEdge('a','c',1);
G.addEdge('b','d',1);
G.addEdge('b','c',1);
G.addEdge('c','e',1);
G.addEdge('c','f',1);
G.addEdge('e','f',1);
unordered_map<char,bool> visited;
G.dfs('a',visited);
return 0;
}