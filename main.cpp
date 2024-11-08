#include <iostream>
#include <vector>
#include "Queue.h"    // Queue class with sort as a member function
#include "Search.h"   // Declaration of recursiveLastOccurrence for Q2

int main() {
    Queue queue;

    // Part 1: Testing Queue Functions (Q1)
    std::cout << "Pushing 10 values into the queue:\n";
    for (int i = 1; i <= 10; ++i) {
        queue.push(i);
        std::cout << "Pushed " << i << " into the queue.\n";
    }

    // Display the contents of the queue after pushing 10 values
    std::cout << "\nThe current contents of the queue are:\n";
    queue.display();

    // Examples of each function
    if (!queue.empty()) {
        std::cout << "\nThe front element is: " << queue.front() << "\n";
    }
    std::cout << "The queue size is: " << queue.size() << "\n";
    std::cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << "\n";
    std::cout << "Moving the front element to the rear...\n";
    queue.move_to_rear();
    queue.display();

    // Continue with Part 1: Popping elements and emptying the queue
    std::cout << "\nPopping two elements from the queue:\n";
    for (int i = 0; i < 2; ++i) {
        if (!queue.empty()) {
            std::cout << "Popped " << queue.front() << " from the queue.\n";
            queue.pop();
        }
    }
    queue.display();

    std::cout << "\nEmptying the queue:\n";
    while (!queue.empty()) {
        std::cout << "Popped " << queue.front() << " from the queue.\n";
        queue.pop();
    }
    if (queue.empty()) {
        std::cout << "The queue is now empty.\n";
    }

    // Part 1 Additional: Testing the sort function
    std::cout << "\nAdding unsorted values to the queue:\n";
    queue.push(5);
    queue.push(3);
    queue.push(8);
    queue.push(1);
    queue.push(2);

    std::cout << "Queue before sorting:\n";
    queue.display();

    queue.sort();

    std::cout << "Queue after sorting:\n";
    queue.display();

    // Part 2: Testing Recursive Last Occurrence Search (Q2)
    std::cout << "\nTesting Recursive Search for the Last Occurrence:\n";

    // Define the vector and print its contents
    std::vector<int> numbers = { 1, 3, 5, 3, 7, 9, 3 };
    int target = 3;

    std::cout << "Vector contents: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\nSearching for the last occurrence of: " << target << "\n";

    // Perform the recursive search
    int lastIndex = recursiveLastOccurrence(numbers, target, numbers.size() - 1);

    if (lastIndex != -1) {
        std::cout << "The last occurrence of " << target << " is at index: " << lastIndex << "\n";
    }
    else {
        std::cout << "The target " << target << " is not in the vector.\n";
    }

    return 0;
}
