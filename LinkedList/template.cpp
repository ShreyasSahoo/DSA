#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->next = NULL;
    }
    Node(int data){
        this->next = NULL;
        this->data = data;
    }
};
void printLL(Node* &head){
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
int countListLength(Node* &head){
    Node * temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
void insertAtHead(Node * &head,int data){
    Node* newNode = new Node(data);
    if(head!=NULL){
    // non empty linked lsit
    newNode->next = head;
    }
    head = newNode;
   
}

void insertAtTail(Node * &tail,int data){
    Node * newNode = new Node(data);
    if(tail!=NULL) tail->next = newNode;
    tail = newNode;
}
// void insertAtAnyPosition(int data, int position, Node* &tail,Node* &head){
//     int length = countListLength(head);
//     if(position<1 || position>length+1){
//         cout<<"Please enter a valid position"<<endl;
//         return;
//     }
//     if(position == 1) insertAtHead(head,data);
//     else if(position == length + 1) insertAtTail(tail,data);
//     else{
//         Node * newNode = new Node(data);
//         Node *prev,*curr = head;
//         while(position != 1){
//             position--;
//             prev = curr;
//             curr = curr->next;
//         }
//         prev->next=newNode;
//         newNode->next= curr;
//     }
    //with one pointer prev
void insertAtAnyPosition(int data, int position, Node* &tail,Node* &head){
    int length = countListLength(head);
    if(position<1 || position>length+1){
        cout<<"Please enter a valid position"<<endl;
        return;
    }
    if(position == 1) insertAtHead(head,data);
    else if(position == length + 1) insertAtTail(tail,data);
    else{
        Node * newNode = new Node(data);
        Node *prev;
        prev->next=head;
        while(position != 1){
            position--;
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
        
    }
    

}
int main(){

Node * first = new Node(10);
Node * second = new Node(20);
Node * third = new Node(30);
Node * fourth = new Node(40);
Node * fifth = new Node(50);
Node * head = first;
first->next = second;
second->next = third;
third->next = fourth;
fourth->next = fifth;

//  printLL(first);
// cout<<countListLength(first);
// insertAtHead(head,0);

Node * empty = NULL;
// insertAtHead(empty,100);
// insertAtTail(fifth,200);
insertAtAnyPosition(100,3,fifth,head);
printLL(head);

// printLL(empty);
return 0;
}