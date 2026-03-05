#include <iostream>

class DoublyLinkedList {
private:
    Node* head;
    Node* tail; // Tail pointer makes end-insertions O(1)

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the front: O(1)
    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at the back: O(1) thanks to the tail pointer
    void insertBack(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // Display from Head to Tail
    void displayForward() {
        Node* temp = head;
        std::cout << "Forward:  ";
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Display from Tail to Head (The unique power of DLL)
    void displayBackward() {
        Node* temp = tail;
        std::cout << "Backward: ";
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "NULL\n";
    }

    // Delete a node: O(n) to find, O(1) to re-link
    void remove(int val) {
        if (!head) return;

        Node* temp = head;
        while (temp && temp->data != val) {
            temp = temp->next;
        }

        if (!temp) return; // Value not found

        if (temp == head) head = temp->next;
        if (temp == tail) tail = temp->prev;

        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;

        delete temp;
        std::cout << "Deleted " << val << "\n";
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertBack(10);
    dll.insertBack(20);
    dll.insertFront(5);

    dll.displayForward();  // 5 <-> 10 <-> 20
    dll.displayBackward(); // 20 <-> 10 <-> 5

    dll.remove(10);
    dll.displayForward();  // 5 <-> 20

    return 0;
}