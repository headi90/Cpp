#include <iostream>

class Node {
public:
    int v;
    Node* next;
};

class List {
    Node* head;

public:
    List()
        : head(NULL){};
    ~List();

    void print();
    void push_back(int val);
    void clear();
};

List::~List()
{
    Node* curr = head;
    Node* n;

    while (curr != NULL) {
        n = curr->next;
        delete (curr);
        curr = n;
    }
    head = NULL;
}

void List::clear()
{
    Node* curr = head;
    Node* n;

    while (curr != NULL) {
        n = curr->next;
        delete (curr);
        curr = n;
    }
    head = NULL;
}

void List::print()
{
    Node* curr = head;

    while (curr) {
        std::cout << curr->v << "->";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}

void List::push_back(int val)
{
    Node* el = new (Node);
    el->v = val;
    el->next = NULL;

    if (head == NULL) {
        head = el;
        return;
    }

    Node* curr = head;
    while (curr && curr->next) {
        curr = curr->next;
    }
    curr->next = el;
}

int main()
{
    List l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.print();
    l.clear();
    l.print();

    return 0;
}
