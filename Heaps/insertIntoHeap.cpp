#include<iostream>
using namespace std;
class Heap{
    public:
    int * arr;
    int size,cap;
    Heap(int cap){
        this->arr = new int[cap];
        this->cap = cap;
        //size = current number of elements
        this->size = 0;
    }
    void insert(int val){

        if(this->size == this->cap){
            cout<<"Heap Overflow"<<endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = val;
        int parentIndex ;
        //until the inserted value is at the root
        while(index>1){
            parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }

    }

    int deletion(){
    int answer = arr[1];
    arr[1] = arr[size];//root ki jagah last node aagaya
    size--;//last node deleted
    //ab root ko sahi jagah pahuchana hai
    int index = 1;
    while(index<size){
        int leftChild = 2*index;
        int rightChild = 2*index+1;
        int indexOfMax = index;
        if(leftChild < size && arr[leftChild] > arr[index] ){
            indexOfMax = leftChild;
        }
        else if(rightChild < size && arr[rightChild] > arr[indexOfMax] ){
            indexOfMax = rightChild;
        }
        if(indexOfMax == index) break;
        else {
            swap(arr[indexOfMax],arr[index]);
            index = indexOfMax;
        }

    }
    return answer;

    }
};
void heapify(int arr[],int n , int index){
    int indexOfMax = index ;
    int leftChild = 2*index ;
    int rightChild = 2*index +1;
    if(leftChild < n && arr[leftChild] > arr[index]) indexOfMax = leftChild;
    if(rightChild < n && arr[rightChild] > arr[index]) indexOfMax = rightChild;
    if(index == indexOfMax) return;
    else{
        swap(arr[index],arr[indexOfMax]);
        index = indexOfMax;
        heapify(arr,n,index);
    }
}
void buildHeap(int arr[],int n){
    for(int i =n/2;i>0;i--){
        heapify(arr,n,i);
    }
}
void heapSort(int arr[],int n){
    while(n!=1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
}
int main(){
Heap h(20);
h.insert(10);
h.insert(20);
h.insert(5);
h.insert(11);
h.insert(6);
for(int i =1;i<6;i++){
    cout<<h.arr[i]<<endl;
}
h.deletion();
cout<<endl<<"after deletion"<<endl;
for(int i =1;i<5;i++){
    cout<<h.arr[i]<<endl;
}


return 0;
}