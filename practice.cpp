#include <iostream>
using namespace std;

 

struct Node{
    int data;
    int index;
    Node* next;
};

struct LinkedList{
    Node* start  = nullptr;
    Node* last = nullptr;
    int length = 0;

    //insertBegin(value)
    void insertBegin(int value){
        if(isEmpty()){
            Node* n = new Node;
            n->data = value;
            n->index = 0;
            n->next = nullptr;
            start = n; 
            last = n;
            length++;
        }
        else{
            Node* n = new Node;
            n->data = value;
            n->index = 0;
            n->next = start;
            start = n;
            length++;
            updateIndices();
        }
    }

    //insertEnd(int value)
    void insertEnd(int value){
        if(isEmpty()){
            Node* n = new Node;
            n->data = value;
            n->index = length;
            n->next = nullptr;

            start = n;
            last = n;
            length++;
        }
        else{
            Node* n  = new Node;
            n->data = value;
            n->index = length;
            n->next = nullptr;

            last->next = n;
            last = n;
            length++;
        }
    }

    //insertAt(int index, int value)
    void insertAt(int index, int value){
        if(index == 0){
            //when user wants to add in the start of list
            insertBegin(value);
        }
        else if(index == lenght-1){
            //when user wants to add in the last of list
            insertEnd(value);
        }
        else if(index > 0 && index < length-1){
            //beech mein kahein pe
            Node* temp = start;

            for(int i = 0 ; i < index-1 ; i++){
                temp = temp->next;
            }

            Node* n = new Node;
            n->data = value;
            n->index = index;
            n->next = temp->next;
            temp->next = n;
            length++;
            updateIndices();
        }
        else{
            cout<<"No Index Found"<<endl;
        }
    }

    



    //display ka method
    void display(){
        Node* temp = start;
        for(int i = 0; i <length; i++){
            cout<<temp->index<<" "<<temp->data<<endl;
            temp = temp->next;
        }
    }


    //============ HELPER FUNC & METHODS ==========
    

    bool isEmpty(){
        return start == nullptr;
    }

    void updateIndices(){
        Node* temp = start;
        for(int i = 0; i < length; i++){
            temp->index = i;
            temp = temp->next;
        }
    }
};



int main(){

    LinkedList l1;

    l1.insertBegin(1);

    l1.display();
    return 0;
}