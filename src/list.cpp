#include <iostream>
#include <random>

#include "list.h"

void List::ShowMenu()
{
    int option;
  
    int counter{1};
    while (!this->exit)
    {
        std::cout << "\n\n===========================\n\n";
        std::cout << "\tEscoge una opción" << std::endl;
        std::cout << "\t1 - Insert Element at the end of list" << std::endl;
        std::cout << "\t2 - Insert Element at first position" << std::endl;
        std::cout << "\t3 - Delete item by value" << std::endl;
        std::cout << "\t4 - Show List" << std::endl;
        std::cout << "\t5 - Exit" << std::endl;

        std::cin >> option;

        std::cout << "\n===========================\n\n"; 

        if( option == 1)
            InsertNode();
        else if(option == 2)
            InsertFirst();
        else if(option == 3)
            DeleteNodeByValue();
        else if(option == 4)
            PrintList();
        else if( option == 5)
        {
            this->exit = true;
            std::cout << "Exit Program" << std::endl;
        }
        ++counter;
    }
}

void List::InsertNode()
{
    
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 100);

    int value = dist(engine);

    Node *n = new Node;
    n->SetData(value); 
    if( head == nullptr )
    {
        head = n;
    }
    else
    {
        Node *temp = head;
        while( temp->GetNext() != nullptr)
        {
            temp = temp->GetNext();
        }
        temp->SetNext(n);
    }
    
    std::cout << "Inserted Item: " << value << std::endl;
}

void List::DeleteNodeByValue()
{
    Node *current, *previous; 

    if( head == nullptr)
    {
        std::cout << "The list is empty" << std::endl;
        return;
    }

    std::cout << "Insert the value to delete: ";
    int value;
    std::cin >> value;

    if( head->GetData() == value )
    {
        Node *current = head;
        head = head->GetNext();
        delete current;
        return;
    }

    current = head;
    previous = head;

    while( current->GetNext() != nullptr && current->GetData() != value)
    {
        previous = current;
        current = current->GetNext();
    } 
        if(current->GetData() == value)
        {
            previous->SetNext(current->GetNext());
            delete current;
            return;
        }
    
    std::cout << "Not found data in the list" << std::endl;
}
void List::InsertFirst()
{
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 100);

    int value = dist(engine);

    Node *n = new Node;
    n->SetData(value); 
    n->SetNext(nullptr);

    if( head == nullptr )
    {
        head = n;
    }
    else
    {
        n->SetNext(head);
        head = n;
    }
    std::cout << "Inserted Item: " << value << std::endl;
}

bool List::EmptyList()
{
    if( head == nullptr)
        return true;
 
    
    return false;
}

void List::PrintList()
{

    if( EmptyList() )
    {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    std::cout << "\n\nPrint List\n" << std::endl;
    Node *current = head;
    while( current->GetNext() != nullptr)
    {
        std::cout << "Next node address: " << current->GetNext() << std::endl;
        std::cout << "Data: " << current->GetData() << std::endl;
        std::cout << "----------" << std::endl;
        current = current->GetNext();
    }

    std::cout << "Next node address: 3" << current->GetNext() << std::endl;
    std::cout << "Data: " << current->GetData() << std::endl;
    std::cout << "----------" << std::endl;

}