#include<iostream>
#include<vector>
using namespace std;
int binarySearchL(int l,vector<int> v){
    int start = 0,end = v.size()-1;
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        
        if(v[mid]<l)
        start = mid +1;
        else 
        end = mid - 1;
    }
    return mid;
}
int binarySearchR(int r,vector<int> v){
    int start = 0,end = v.size()-1;
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        
        if(v[mid]<=r)
        start = mid +1;
        else 
        end = mid - 1;
    }
    return mid;
}
int main(){
int l,r;
cin>>l>>r;
int inp=0;
vector<int> v;
while(inp != -1){
cin>>inp;
v.push_back(inp);
}
int index1 = binarySearchL(l,v);
int index2 = binarySearchR(r,v);
cout<<"number of elements in the range "<<l<< " and "<<r<<" -> "<<index2-index1 -1;
return 0;
}