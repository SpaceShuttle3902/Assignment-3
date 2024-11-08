#include "Queue.h"
#include <iostream>

Queue::Queue() : front_of_queue(nullptr), back_of_queue(nullptr), num_items(0) {}

Queue::~Queue() {
    while (!empty()) {
        pop();
    }
}

void Queue::push(int item) {
    Node* newNode = new Node(item);
    if (empty()) {
        front_of_queue = back_of_queue = newNode;
    }
    else {
        back_of_queue->next = newNode;
        back_of_queue = newNode;
    }
    ++num_items;
}

void Queue::pop() {
    if (empty()) {
        throw std::out_of_range("Queue is empty - cannot pop");
    }
    Node* old_front = front_of_queue;
    front_of_queue = front_of_queue->next;
    if (front_of_queue == nullptr) {
        back_of_queue = nullptr;
    }
    delete old_front;
    --num_items;
}

int Queue::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty - no front element");
    }
    return front_of_queue->data;
}

int Queue::size() const {
    return num_items;
}

bool Queue::empty() const {
    return num_items == 0;
}

void Queue::move_to_rear() {
    if (empty()) {
        throw std::out_of_range("Queue is empty - cannot move front to rear");
    }
    int frontItem = front();
    pop();
    push(frontItem);
}

void Queue::display() const {
    Node* current = front_of_queue;
    std::cout << "Queue contents: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

// Function to perform insertion sort on the queue
void Queue::sort() {
    if (front_of_queue == nullptr || front_of_queue->next == nullptr) {
        return; // Queue is empty or has only one element
    }

    Node* sorted = nullptr; // Start with an empty sorted list

    while (front_of_queue != nullptr) {
        Node* current = front_of_queue;
        front_of_queue = front_of_queue->next;

        // Insert `current` into the sorted list
        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    // Update the queue to the sorted list
    front_of_queue = sorted;

    // Update the back_of_queue pointer
    Node* temp = front_of_queue;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    back_of_queue = temp;
}
