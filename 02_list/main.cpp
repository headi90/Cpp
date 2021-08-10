#include <iostream>

class Node {
public:
    int v;
    Node* next;
};

void push_back(Node** l, int val)
{
    Node* el = new (Node);
    el->v = val;
    el->next = NULL;

    if (*l == NULL) {
        std::cout << "list null\n";
        *l = el;
        return;
    }

    Node* curr = *l;
    while (curr && curr->next) {
        curr = curr->next;
    }
    curr->next = el;
}

void print(Node* l)
{
    while (l != NULL) {
        std::cout << l->v << ", ";
        l = l->next;
    }
    std::cout << '\n';
}

int main()
{
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    print(head);
    return 0;
}
