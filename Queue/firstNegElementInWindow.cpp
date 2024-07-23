#include<iostream>
#include<queue>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        //    {12, -1, -7, 8, -15, 30, 16, 28}    
        queue<int> q;
        vector< long long int> ans;
        //first window processing
        for(int i=0;i<K;i++){
            if(A[i]<0){
                q.push(i);
            }
        }
        //[{1} , 2,4]
        for(int i = K;i<N;i++){//here i signifies the index of the last element of the curr window 
            if(q.empty()){
                ans.push_back(0);
            }
            else ans.push_back(A[q.front()]);
            //ans = [1,1,2]
            //removal - check if q.front() is in the current window
            if(!q.empty() && i - q.front() >= K){
                q.pop();
            }
            //addition - if A[i] is neg then add it to the queue
            if(A[i]<0){
                q.push(i);
            }
            
           
        }
        //last window processing , as in every iteration we update the answers for the last window
        if(q.empty()){
                ans.push_back(0);
            }
            else ans.push_back(A[q.front()]);
        return ans;
        
                                             }  
int main(){

return 0;
}