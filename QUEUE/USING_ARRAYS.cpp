#include <iostream>

class CircularQueue {
private:
    int* arr;
    int front, rear, size;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // Add element to the back
    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            std::cout << "Queue is Full\n";
            return;
        }

        if (front == -1) front = 0; // First element being added

        rear = (rear + 1) % size;
        arr[rear] = value;
        std::cout << "Enqueued: " << value << "\n";
    }

    // Remove element from the front
    void dequeue() {
        if (front == -1) {
            std::cout << "Queue is Empty\n";
            return;
        }

        std::cout << "Dequeued: " << arr[front] << "\n";

        if (front == rear) {
            // Only one element was present, reset queue
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) return;

        int i = front;
        while (true) {
            std::cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        std::cout << "\n";
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.display(); // Outputs: 20 30
    return 0;
}