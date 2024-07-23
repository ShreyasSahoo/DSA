#include<bits/stdc++.h>
using namespace std;
int main(){
	//pair 
	pair<string, int> p = {"Shreyas",21};
	cout<<p.first<<" "<<p.second<<endl;
	//nested pair
	pair<int, pair<int,int> > nestedPair = {1,{2,3}};
	cout<<nestedPair.first<<endl;
	// cout<<nestedPair.second<<endl; - gives error
	cout<<nestedPair.second.first<<endl;
	cout<<nestedPair.second.second<<endl;
	// array of pairs 
	pair<int,int> arrayOfPairs[] = {{1,2},{3,4},{5,6}};
	cout<<arrayOfPairs[1].first<<endl;

	//vector
	cout<<"Vectors "<<endl;
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.emplace_back(20); // similar but faster than push_back
	//It avoids the overhead of creating a temporary object and then copying or moving it into the container.
	cout<<v[0]<<endl;
	// In summary, use push_back when you want to add an already constructed object to the container, and use emplace_back when you want to construct the object in-place, potentially avoiding unnecessary copies or moves.

	vector<pair<int,int>> vectorOfPairs;

	vectorOfPairs.push_back({1,2});
	vectorOfPairs.emplace_back(3,4);
	cout<<vectorOfPairs[0].first<<endl;
	// cout<<vectorOfPairs[1];

	//copying a vector 
	vector <int> v2(v);
	cout<<v2[1]<<endl;
	
	//iterating over vectors
	vector<int>::iterator it;

	for ( it = v.begin(); it != v.end() ; it++)
	{
		cout<< *(it)<<endl;
	}

	for ( auto it2 = v.begin(); it2 != v.end() ; it2++)
	{
		cout<< *(it2)<<endl;
	}
	

	v.push_back(100);
	v.insert(v.end(),200);
	//for each loop
	for (auto it : v){
		cout<< it;
	}

	//list - container - gives front operations as well, which can be done in vectors using insert but it is much more costly
	//list uses doubly linked list internally

	list<int> ls;
	ls.push_front(10);
	ls.push_front(20);
	for( auto it : ls){
		cout<<endl<<it;
	}
	//all other methods are same as vectors

	//stack - contianer - LIFO

	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.pop();
	cout<<st.top();
	//all operations push pop and top are O(1)
	//size(),empty(),top()

	//queue - container - FIFO
	
	queue<int> que;
return 0;
}