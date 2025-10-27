#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    int val;
    node(int data){
        val = data;
        next=NULL;
    }
};
class linkedList{
    public:
    node* head;
    linkedList(){
        head = NULL;
    }
    void insertAtEnd(int val){
        node* newNode = new node(val);
        newNode->next=NULL;
        node* temp = head;
        if(head==NULL){
            head = newNode;
            return;
        }
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=newNode;
    }
    void display(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    node* reversell(){
        node* currentPtr=head;
        node* previousPtr = NULL;
        while(currentPtr!=NULL){
            node* nextPtr = currentPtr->next;
            currentPtr->next=previousPtr;
            previousPtr=currentPtr;
            currentPtr=nextPtr;
        }
        node* newHead = previousPtr;
        return newHead;
        
    }
};
int main(){
    linkedList ll;
    for(int i = 0;i<7;i++){
        ll.insertAtEnd(i+1);
    }
    ll.display();
    ll.head=ll.reversell();
    ll.display();
    return 0;
}