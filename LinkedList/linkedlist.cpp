#include "linkedlist.h"
#include <stdlib.h>

LinkedList::LinkedList()
{
    head_ = nullptr;
}

void destoryList(node* head)
{
    if (head == nullptr) return;

    while (head)
    {
        if (head->next)
            destoryList(head->next);
        else
        {
            delete head;
            head = nullptr;
        }
    }
}

LinkedList::~LinkedList()
{
    destoryList(head_);
}

void
LinkedList::append(int value)
{
    if (head_ == nullptr)
    {
        head_ = (node*)malloc(sizeof(node));
        head_->data = value;
        head_->next = nullptr;
    }
    else
    {
        node* tempHead = head_;
        while (tempHead)
        {
            if (tempHead->next == nullptr)
            {
                node* newNode = (node*)malloc(sizeof(node));
                newNode->data = value;
                newNode->next = nullptr;
                tempHead->next = newNode;
                break;
            }
            tempHead = tempHead->next;
        }
    }
}

void
LinkedList::prepend(int value)
{
    if (head_ == nullptr)
    {
        head_ = (node*)malloc(sizeof(node));
        head_->data = value;
        head_->next = nullptr;
    }
    else
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = value;
        head_->next = newNode;
    }
}

void
LinkedList::insert(int value)
{
}

bool
LinkedList::search(int value)
{
   if (head_ == nullptr) return false;

   while (head_)
   {
        if (head_->data == value)
            return true;

        head_ = head_->next;
   }
   return false;
}
