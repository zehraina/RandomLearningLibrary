#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
struct node {
    int data;
    struct node* prev;
    struct node* next;
};


struct node *head, *tail=NULL; 

void display() {  
   
    struct node *current = head;  
    if(head == NULL) {  

        return;  
    }  

    while(current != NULL) {  
       
        cout<< current->data;  
        current = current->next;  
    }  
}  
void InsertAtBeg(int n){
    struct node* nnode=(struct node*) malloc(sizeof(struct node*));
    nnode->data=n;
    if (head==NULL){
        head=tail=nnode; head->prev=NULL; tail->next=NULL;
    }
    else {
        nnode->next=head;
        nnode->prev=NULL;
        head=nnode;
    }
    
}

void InsertAtPos(int n, int pos){
    struct node* nnode=(struct node*) malloc(sizeof(struct node*));
    struct node* temp=(struct node*) malloc(sizeof(struct node*));
    temp=head;
    nnode->data=n;
    if (pos==2){
        head->next->prev=nnode;
        nnode->next=head->next;
        head->next=nnode;
        nnode->prev=head;
    }
    if (pos==1) InsertAtBeg(n);
    if (pos>2){
          for (int i=1;i<pos-1;i++){

            temp=temp->next;
          }
          temp->next->prev=nnode;
          nnode->next=temp->next;
          nnode->prev=temp;
          temp->next=nnode;
          
    }
}

void InsertAtEnd(int n){
    struct node* nnode=(struct node*) malloc(sizeof(struct node*));
    nnode->data=n;
      tail->next=nnode;
        nnode->prev=tail;
        nnode->next=NULL;
        tail=nnode;
}

void DelFromBeg(){
    struct node* temp=(struct node*) malloc(sizeof(struct node*));
    temp=head->next;

    temp->prev=NULL;
    free(head);
    head=temp;
    
}

void DelAtPos(int pos){
    struct node* temp=(struct node*) malloc(sizeof(struct node*));
    temp=head;
    if (pos==1){
        DelFromBeg();
    }
    if (pos==2){
       temp=head->next;
       head->next=temp->next;
       temp->next->prev=head;
       free(temp);

    }
    if (pos>2){
        int i=1;
         while(i<pos){
              temp=temp->next;
              i++;
         }
         if (temp->next==NULL){
            temp->prev->next=NULL;
            temp->prev=tail;
            free(temp);
         }
          else {temp->prev->next=temp->next;
               temp->next->prev=temp->prev;
               free(temp);
          }
    }
}

void DelAtEnd(){
    struct node* temp=(struct node*) malloc(sizeof(struct node*));
    temp=tail->prev;
    
    free(tail);
    tail=temp;
}


int main(){
    int n, x, pos;
    while(true){
    
            cout<<"ENter choice"<<endl;
            cin>>n;
          switch (n){
                 case 1: cin>>x; 
                         InsertAtBeg(x);  
                         break;
               
               
                 case 2:  
                         cin>>x;
                         cin>>pos;
                         InsertAtPos(x, pos);
                         break;
                case 3: 
                         cin>>x;
                         InsertAtEnd(x);  break;
                case 4: 
                         DelFromBeg();  break;
                case 5: 
                         cin>>pos;
                           DelAtPos(pos);
                case 6:
                        DelAtEnd();
                case 7: 
                        display();
    
         };
    
    }

return 0;
}