#include<iostream>

struct Node{
    int data;
    int index;
    Node* next;
};

struct LinkedList{
    Node* start = nullptr;
    Node* last = nullptr;
    int length = 0;

    void addANewNode(int value){
        Node* n = new Node;
        n->data = value;
        n->index = length;
        n->next = nullptr;

        if(length == 0){
            start = n;
            last = n;
        }
        else{
            last->next = n;
            last = n;
        }
        length++;
    }

    void display(){
        Node* temp = start;
        for(int i = 0; i <length; i++){
            cout<<temp->index<<" "<<temp->data<<endl;
            temp = temp->next;
        }
    }


    //insertBegin(value)
    void insertBegin(int value){
        if(isEmpty()){
            //agar list empty howi tou
            Node* n = new Node;
            n->data = value;
            n->index = 0;
            n->next = nullptr;

            start = n;
            last = n;
            length++;
        }
        else{
            //warna
            Node* n = new Node;
            n->data = value;
            n->index = 0;
            n->next = start;
            start = n;
            length++;
            updateIndices();
        }
    }

    //insertEnd(value)
    void insertEnd(int value){
        if(isEmpty()){
            //agar list empty howi tou ye karo

            //ye ik khali daba banayega
            Node* n = new Node;

            //is dabay ki value woh hogi jo user dega
            n->data = value;
            
            //isko index zero hogi kion kay ye akela node hai puri list mein
            n->index = 0;

            //iske bad koi node nahi isliye nullptr ko point karegaa
            n->next = nullptr;

            //start is node ke upar kin kay ye akela node hai
            start = n;
            
            //same last ke sath bhi
            last = n;

            length++;
        }
        else{
            //warna ye karo
            Node* n = new Node;
            n->data = value;
            n->index = length;
            n->next = nullptr;
            last->next = n;
            last = n;
            length++;
        }
    }

    //insertAt(index, value)

    //========= HELPER FUNCS & METHODS ============
    bool isEmpty(){
        return start == nullptr;
    }

    void updateIndices(){
        Node* temp  =start;
        for(int i = 0 ; i < length; i++){
            temp->index = i;
            temp = temp->next;
        }
    }


};

int main(){


    LinkedList myList;

    return 0;
}