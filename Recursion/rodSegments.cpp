#include<iostream>
using namespace std;
int segmentsOfRod(int n, int x,int y,int z){
    if(n==0)
    return 0;
    if(n<0)
    return INT_MIN;
    int option1 = 1 + segmentsOfRod(n-x,x,y,z);
    int option2 = 1 + segmentsOfRod(n-y,x,y,z);
    int option3 = 1 + segmentsOfRod(n-z,x,y,z);
    int finalAns = max(option1 , max(option2, option3));
    return finalAns;
}
int main(){
cout<<segmentsOfRod(10,3,2,4);
return 0;
}