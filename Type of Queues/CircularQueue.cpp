#include<iostream>
using namespace std;
// Using circular loop with static memory 
// maintaining circular behaviour through GCD modulo
#define SIZE 5  // Queue can hold maximum 5 elements
int queue[SIZE];
int rear = -1;    // points to last element (intially empty)
int front = -1;  // points to first element (initially empty)

void enqueue(int value) {
    if((rear +1)% SIZE == front) {
        cout<<" Queue Overflow";
        return;

    }
    if(front ==-1){
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1)% SIZE;
    }
    queue[rear] = value;
    cout<< value << " enqueued to queue" << endl;
}

int dequeue() {
    if(front == -1) {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front +1) % SIZE;
    }
    return value;
}
int peek() {
    if(front == -1){
        cout<< " QUeue is empty!"<< endl;
        return -1;
    }
    return queue[front];
}
void display () {
    if(front == -1) {
        cout<< "Queue is empty!" << endl;
        return;
    }
    cout<< "Queue elements: ";
    int i = front;

    if(front <= rear){
        while (i  <= rear) {
            cout << queue[i] << " ";
            i++;
        }
    }
    else {
        while(i < SIZE) {
            cout<< queue[i] << " ";
            i++;
        }
        i = 0;
        while (i <= rear) {
            cout<< queue[i] << " ";
            i++;
        }
    }
    cout<< "\n";
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    cout<< "Front element :"<< peek() << endl;
    cout<< " Dequeued: " << dequeue() <<endl;
    cout<< "Dequeued: "<< dequeue() << endl;
    display();

    enqueue(50);
    enqueue(60);

    display();
    enqueue(70);   // THis will show overflow
    return 0; 

}


