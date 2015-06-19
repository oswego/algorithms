#pragma once

struct node
{
    int data;
    node* next;
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void append(int value);
    void prepend(int value);
    void insert(int value);
    bool search(int value);

private:
    node* head_;
};
