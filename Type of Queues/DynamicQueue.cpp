#include<iostream>
using namespace std;
// Dynamic queue
struct QNode {
    int data;
    QNode * QNext = NULL;
};
struct QNode * rear = NULL;
struct QNode * front = NULL;
// Creating a new node
QNode* NewNode (int value) {

    QNode * tmp =(QNode *)malloc(sizeof(QNode));
    if(tmp == NULL) {
        cout<< "\n Memory allocation failed.";
        exit(1) ;

    }
    tmp -> data = value;
    tmp -> QNext = NULL;
    return tmp;
}
void enqueue (int value){
    QNode* tmp = NewNode(value);
    if(rear == NULL) {
        front = rear = tmp;
        return;
    }
    rear->QNext = tmp;
    rear = tmp;
}
int dequeue(int value){
    if(front ==NULL){
        cout<< "Queue Underflow";
        return -1;
    }
    value = front->data;
    QNode* tmp = front;
    front ->QNext;

    if(front == NULL){
        rear = NULL;
    }
    free(tmp);
    return value;
}
void display(){
    if(front == NULL) {
        cout<<"\nQueue is empty";
        return;
    }
    cout<< "Queue: ";
    QNode* tmp = front;
    while(tmp != NULL){
        cout<<tmp -> data << ",";
        tmp = tmp ->QNext;
    }
    cout<< "\n";
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    cout<<"Dequeue: " << dequeue(20);
    display();
    enqueue(40);
    enqueue(50);
    display();
    return 0;
}

