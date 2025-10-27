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
    void returnMiddle(){
        int count=1;
        node* temp = head;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        cout<<"Number of nodes: "<<count<<endl;
        count = (count/2)+1;
        node* temp2=head;
        while(count>1){
            temp2=temp2->next;
            count--;
        }
        cout<<"Middle value: "<<temp2->val<<endl;
        
    }
};
int main(){
    linkedList ll;
    for(int i = 0;i<7;i++){
        ll.insertAtEnd(i+1);
    }
    ll.display();
    ll.returnMiddle();
    return 0;
}