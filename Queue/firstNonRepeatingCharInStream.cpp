#include<iostream>
#include<queue>
using namespace std;
string FirstNonRepeating(string A){
		    // Code here
		    queue<int> q;
		    string ans;
		   int freq[26]={0};
		    int n = A.size();
		    for(int i=0;i<n;i++){
		        int charIndex = int(A[i])-97;
		            freq[charIndex]++;
		            q.push(charIndex);
		            while(!q.empty() && freq[q.front()] != 1){
		                q.pop();
		            }
		            if(q.empty()) ans.push_back('#');
		            else ans.push_back(char(q.front()+97));
		            
		    }
		            return ans;
		}
int main(){

return 0;
}