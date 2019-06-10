#ifndef NODE_H
#define NODE_H


class Node
{
private:
    char data;
    Node* next;
    Node* prev;
public:
    Node();
    Node(const char&);

    char getData()const;
    Node *getNext() const;
    Node *getPrev() const;

    void setData(const char&);
    void setNext(Node*);
    void setPrev(Node*);
};

#endif // NODE_H
