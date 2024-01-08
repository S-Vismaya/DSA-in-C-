#include <iostream>
using namespace std;

struct ListNode{
 int val;
 ListNode* next;
 ListNode():val(0),next(nullptr) {}
 ListNode(int x):val(x),next(nullptr) {}
 ListNode(int x,ListNode* next):val(x),next(next) {}
};

ListNode* findIntersection(ListNode* head1,ListNode* head2){
 ListNode* a=head1;
 ListNode* b=head2;

 while(a!=b){
  a=a->next;
  b=b->next;
  if(a==b) return a;
  a= (a==NULL)?head2:a->next;
  b= (b==NULL)?head1:b->next;
 }
 return a;
}

void insertNode(ListNode* head,int x){
 ListNode* newnode = new ListNode(x);
 if(!head) {
  head=newnode;
 }else{
 while(head->next!=NULL){
  head=head->next;
 }
 }
 head->next=newnode;
}

void display(ListNode* head){
 if(head==NULL) return;
 while(head->next!=NULL){
  cout<<head->val<<"->";
  head=head->next;
 }
 cout<<head->val;
}

int main(){
 ListNode* head1=NULL;
 insertNode(head1,1);
 insertNode(head1,2);
 insertNode(head1,3);
 display(head1);

 ListNode* head2=NULL;
 insertNode(head2,1);
 insertNode(head2,1);
 display(head2);

 ListNode* intersectionPoint = findIntersection(head1,head2);
 if(intersectionPoint==NULL)
  cout<<"No Intersection"<<endl;
 else
  cout<<"Intersection Point is "<<intersectionPoint->val<<endl;

}
