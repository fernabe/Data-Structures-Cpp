#ifndef NODE_H
#define NODE_H

class  Node
{
private:
    Node *next{nullptr};
    int data;

public:
    //Node();
    ~Node(){};

    void SetNext(Node *next);
    void SetData(int x);

    Node* GetNext();
    int GetData();
};



#endif