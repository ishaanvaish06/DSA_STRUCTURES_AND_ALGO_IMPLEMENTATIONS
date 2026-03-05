#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    q.push(10); // Add to back
    q.push(20);
    q.push(30);

    std::cout << "Front element: " << q.front() << std::endl; // 10

    q.pop(); // Removes 10

    std::cout << "New front: " << q.front() << std::endl; // 20
    std::cout << "Queue size: " << q.size() << std::endl;

    return 0;
}