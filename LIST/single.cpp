#include <iostream>

// The building block of the list
struct Node {
    int data;
    Node* next;

    // Constructor for quick node creation
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // Initialize empty list
    LinkedList() : head(nullptr) {}

    // 1. Insert at the beginning: O(1)
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        std::cout << "Inserted " << val << " at head.\n";
    }

    // 2. Insert at the end: O(n)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        std::cout << "Inserted " << val << " at end.\n";
    }

    // 3. Delete the first occurrence of a value: O(n)
    void remove(int val) {
        if (head == nullptr) return;

        // If the head itself holds the value
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            std::cout << "Deleted " << val << " from the list.\n";
        } else {
            std::cout << val << " not found in the list.\n";
        }
    }

    // 4. Print the entire list: O(n)
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // 5. Destructor: Cleans up memory when the object is destroyed
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        std::cout << "Memory cleared. List destroyed.\n";
    }
};

int main() {
    LinkedList myList;

    // Demonstrating operations
    myList.insertAtHead(10);
    myList.insertAtHead(5);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);

    std::cout << "\nCurrent List: ";
    myList.display();

    myList.remove(20);

    std::cout << "After removing 20: ";
    myList.display();

    return 0; // Destructor is automatically called here
}