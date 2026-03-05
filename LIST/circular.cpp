#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularList {
private:
    Node* head;

public:
    CircularList() : head(nullptr) {}

    // Insert at the end: O(n)
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
            return;
        }

        Node* temp = head;
        // Traverse until we find the node that points back to head
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Display the list: O(n)
    void display() {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head); // Stop when we wrap back to head

        std::cout << "(Back to Head: " << head->data << ")\n";
    }

    // Delete a node: O(n)
    void remove(int val) {
        if (!head) return;

        Node *curr = head, *prev = nullptr;

        // Special case: Deleting the head
        if (head->data == val) {
            // If only one node exists
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            // Find the last node to update its pointer
            Node* last = head;
            while (last->next != head) last = last->next;

            Node* temp = head;
            last->next = head->next;
            head = head->next;
            delete temp;
            return;
        }

        // Searching for the node
        do {
            prev = curr;
            curr = curr->next;
        } while (curr != head && curr->data != val);

        if (curr->data == val) {
            prev->next = curr->next;
            delete curr;
        }
    }

    ~CircularList() {
        if (!head) return;
        Node* curr = head;
        Node* nextNode;

        // Break the circle to delete normally
        Node* last = head;
        while (last->next != head) last = last->next;
        last->next = nullptr;

        while (curr) {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};

int main() {
    CircularList cl;
    cl.insert(1);
    cl.insert(2);
    cl.insert(3);

    std::cout << "Circular List: ";
    cl.display(); // 1 -> 2 -> 3 -> (Back to Head: 1)

    cl.remove(2);
    std::cout << "After removing 2: ";
    cl.display();

    return 0;
}