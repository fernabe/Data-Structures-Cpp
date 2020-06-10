#ifndef LIST_H
#define LIST_H

#include "node.h"

class List
{
    public:
        List()
        {
            head = nullptr;
        };
        ~List(){};
        void ShowMenu();
    private:
        Node *head;
        void InsertNode();
        void InsertFirst();
        void PrintList();
        bool EmptyList();
    
        bool exit{false};
};


#endif