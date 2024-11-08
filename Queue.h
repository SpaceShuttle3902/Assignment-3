#ifndef SOURCE_H
#define SOURCE_H

#include <stdexcept>
#include <iostream>

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* front_of_queue;
    Node* back_of_queue;
    int num_items;

public:
    Queue();
    ~Queue();
    void push(int item);
    void pop();
    int front() const;
    int size() const;
    bool empty() const;
    void move_to_rear();
    void display() const;
    void sort();  // Declaration of the new sort function
};

#endif // SOURCE_H
