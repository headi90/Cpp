#include <iostream>

struct Node {
    int data;
    Node* next;
};

void push_back(Node** l, int val)
{
    Node* el = new (Node);
    el->data = val;
    el->next = nullptr;

    if (*l == NULL) {
        *l = el;
        return;
    }

    Node* curr = *l;
    while (curr && curr->next) {
        curr = curr->next;
    }
    curr->next = el;
}

void printList(Node* head)
{
    Node* curr = head;

    while (curr != nullptr) {
        std::cout << curr->data << " --> ";
        curr = curr->next;
    }
    std::cout << '\n';
}

void deleteList(Node** head)
{
    Node* curr = *head;

    while (curr->next != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    *head = nullptr;
}

void reverseList(Node** head)
{
    Node* previous = nullptr;
    Node* current = *head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}

int main()
{
    Node* head = nullptr;

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);
    printList(head);
    reverseList(&head);
    printList(head);

    deleteList(&head);
    printList(head);
    return 0;
}