#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
  ListNode* reverseList(ListNode* head){
        ListNode *prev=NULL,*curr=head;
        ListNode* next=NULL;
        
        while(curr != NULL){
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
        }
        head = prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {

        // ListNode* head2 = reverseList(head);
         ListNode* curr1=head;//*curr2=head2;
        // while(head1 != NULL && head2 != NULL){
        //     if(curr1->val != curr2->val) return false;
        //     cout<<"LL1 - "<<head1<<endl;  
        //     cout<<"LL2 - "<<head2<<endl;  
        //     head1 = head1->next;
        //     head2 = head2->next;
        // }
        while(curr1 != NULL){
            cout<<curr1->val<<"->";
            curr1 = curr1->next;
        }
        // cout<<"LL1 - "<<head1<<endl;  
        //     cout<<"LL2 - "<<head2<<endl;  
        // cout<<"true hone wala hai";
        return true;
    }
    void printLL(ListNode* head){
        ListNode*temp=head;
        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
    }
int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(1);
    ListNode* third = new ListNode(2);
    ListNode* fourth = new ListNode(1);
    first->next = second;
    second->next = third;
    third->next = fourth;
    ListNode * reversedHead = reverseList(first);
    // printLL(reversedHead);
   bool a =  isPalindrome(first);
//    cout<<a;
return 0;
}