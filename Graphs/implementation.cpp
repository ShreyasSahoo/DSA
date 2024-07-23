#include<iostream>
#include<list>
using namespace std;
class Graph{
public:
unordered_map<int , list<int> > adjList;
void printAdjList(){
    for (auto i : adjList)
    {
        int u = i.first;
        list<int> neighbours = i.second;
        cout<<u<<" -> { ";
       for(auto neighbour: neighbours){
            cout<<neighbour<<", ";
       }
       cout<<"}"<<endl;
    }
       cout<<"--------------"<<endl;
    
}
void addEdge(int start,int end, bool isDirected){
    if(isDirected){
        adjList[start].push_back(end);
    }
    else{
        adjList[start].push_back(end);
        adjList[end].push_back(start);
    }
    printAdjList();
}

};
int main(){ 
Graph G;
G.addEdge(1,3,0);
G.addEdge(2,1,1);
G.addEdge(4,3,0);
G.addEdge(2,4,1);
return 0;
}  