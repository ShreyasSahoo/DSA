#include <bits/stdc++.h> 
using namespace std;
void secondLargest(int size, vector<int> &arr){
    int secondLargest = -1,largest=arr[0];
    for(int i =1;i<size;i++){
        if(arr[i]>largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && secondLargest != -1) secondLargest = arr[i];
    }
    cout<<secondLargest<<endl;
}
int main()
{
    int n;
    cin>>n;
   while(n--){
       int size;
       vector<int> arr;
       cin>>size;
       for(int i=0;i<size;i++){
           int a;
           cin>>a;
           arr.push_back(a);
       }
       secondLargest(size,arr);
   }
   return 0;
}