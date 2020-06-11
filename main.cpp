//
//  main.cpp
//  Hash Function
//
//  Created by Kumar Aditya Jain on 10/06/20.
//  Copyright © 2020 Kumar Aditya Jain. All rights reserved.
//

#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node hash_table[10];
int  hash_function(int value){
    return (value%10);
}

void insert_data(int value){
    
    int index=hash_function(value);
    if(hash_table[index].next==NULL){
        node* n;
        n=new node;
        hash_table[index].next=n;
        n->data=value;
        n->next=NULL;
        cout<<n->data;
        
    }
    else{
        node*t;
        t=hash_table[index].next;
        while(t->next!=NULL){
            t=t->next;
        }
        node*n;
        n=new node;
        t->next=n;
        n->next=NULL;
        n->data=value;
    }
}
void print_data(){
    
    for(int i=0;i<10;i++){
        node *t;
        t=hash_table[i].next;
        cout<<i<<"-->";
        while(t!=NULL) {
            cout<<t->data<<"-->";
                t=t->next;
            }
        cout<<"\n";
    }
}

void search(){
    int value;
    cout<<"Enter the value you want to search";
    cin>>value;
    int index=hash_function(value);
    node* t;
    int c=0;
    t=hash_table[index].next;
    while(t!=NULL){
    if(t->data==value){
        cout<<"\nElement Found";
        cout<<"\nIndex:"<<index;
        cout<<"\nPosition:"<<c;
        break;
    }
    else{
        t=t->next;
        c++;
       
    }
  }
}
void delete_data(){
    int value;
    cout<<"Enter the value you want to search";
    cin>>value;
    int index=hash_function(value);
    node* t;
    t=hash_table[index].next;
    if(t->data==value){
        t=t->next;
        hash_table[index].next=t;
                
    }
    else{
        node* bt;
        bt=t;
        t=t->next;
    while(t!=NULL){
        if(t->data==value){
            if((t->next=NULL)){
                node* temp;
                temp=t;
                delete[]temp;
                break;
            }
            else{
                node* temp;
                temp=t;
                t=t->next;
                bt->next=t;
                delete[]temp;
                break;
                
            }
        }
        t=t->next;
        bt=bt->next;
          
    }
    }
}
    
int main(){
    for(int i=0;i<10;i++)
    {
        hash_table[i].data=0;
        hash_table[i].next=NULL;
      
    }
    
    int response;
    int v;
   label: cout<<"\nPress 1 to insert data";
    cout<<"\nPress 2 to delete data";
    cout<<"\nPress 3 to search data";
    cout<<"\nPress 4 to Print data";
    cout<<"\nPress 5 to continue";
    cout<<"\nPress 6 to exit";
    cin>>response;
       switch (response) {
         case 1:
            cout<<"Enter the value: ";
            cin>>v;
               insert_data(v);
            goto label;
            break;
         case 2:
            delete_data();
            goto label;
            break;
         case 3:
               search();
            goto label;
            break;
         case 4:
            print_data();
            goto label;
            break;
        case 5:
            goto label;
            break;
        case 6:
            cout<<"\nThank You";
               break;
         default:
            cout<<"Wrong option";
            break;
    }
    
       return 0;
}




