#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> numbers = {10, 20, 30};

    numbers.push_back(40);  // {10, 20, 30, 40}
    numbers.push_front(5);  // {5, 10, 20, 30, 40}

    auto it = std::find(numbers.begin(), numbers.end(), 10);
    if (it != numbers.end()) {
        numbers.insert(++it, 15); // {5, 10, 15, 20, 30, 40}
    }

    // 4. Removing elements
    numbers.remove(30); // Removes all elements with value 30
    numbers.pop_front(); // Removes the 5

    // 5. Iterating and Printing
    std::cout << "List contents: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}