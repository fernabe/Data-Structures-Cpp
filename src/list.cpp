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
        std::cout << "\t1 - Insert Element" << std::endl;
        std::cout << "\t2 - Show List" << std::endl;
        std::cout << "\t3 - Exit" << std::endl;

        std::cin >> option;

        std::cout << "\n===========================\n\n"; 

        if( option == 1)
            InsertNode();
        else if(option == 2)
            PrintList();
        else if( option == 3)
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


bool List::EmptyList()
{
    if( head == nullptr)
        return true;
 
    
    return false;
}

void List::PrintList()
{
    std::cout << "\n\nPrint List\n" << std::endl;
    Node *current = head;
    while( current->GetNext() != nullptr)
    {
        std::cout << "Next node address: " << current->GetNext() << std::endl;
        std::cout << "Data: " << current->GetData() << std::endl;
        std::cout << "----------" << std::endl;
        current = current->GetNext();
    }

    std::cout << "Next node address: " << current->GetNext() << std::endl;
    std::cout << "Data: " << current->GetData() << std::endl;
    std::cout << "----------" << std::endl;

}