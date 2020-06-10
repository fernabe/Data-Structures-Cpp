#include <iostream>
#include <node.h>


void Node::SetNext(Node *next)
{
    this->next = next;
}

void Node::SetData(int x)
{
    this->data = x;
}

Node* Node::GetNext()
{ 
    return this->next;
}

int Node::GetData()
{
    return this->data;
}