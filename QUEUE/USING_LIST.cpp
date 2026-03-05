#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Add element to the end (Rear)
    void enqueue(int val) {
        Node* newNode = new Node(val);

        // If queue is empty, both front and rear point to the new node
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        // Add the new node at the end and update rear
        rear->next = newNode;
        rear = newNode;
        std::cout << "Enqueued: " << val << "\n";
    }

    // Remove element from the beginning (Front)
    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue Underflow (Empty)\n";
            return;
        }

        Node* temp = front;
        std::cout << "Dequeued: " << temp->data << "\n";

        front = front->next;

        // If front becomes null, rear must also be null
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    int peek() {
        return (front != nullptr) ? front->data : -1;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.enqueue(30);

    std::cout << "Front element: " << q.peek() << "\n";
    return 0;
}