#include "../model/model.cpp"

void pushPQ(char *name, int day, char *month, int year)
{
    Node *temp = createNode(name, day, month, year);
    if (!head) // tidak ada node
    {
        head = tail = temp;
    }
    else if (year < head->year) // nilai lebih kecil dari head
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else if (year > tail->year) // nilai lebih besar dari tail
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else // nilai diantara head dan tail
    {
        Node *curr = head;
        while (curr && curr->next->year < temp->year)
        {
            curr = curr->next;
        }

        curr->next->prev = temp;
        temp->next = curr->next;

        curr->next = temp;
        temp->prev = curr;
    }
}

void print()
{
    Node *curr = head;
    while (curr)
    {
        printf("%d %s %d - %s\n", curr->day, curr->month, curr->year, curr->name);
        curr = curr->next;
    }
}

void popHead()
{
    if (head && head == tail)
    {
        head = tail = NULL;
        free(head);
    }
    else
    {
        Node *newHead = head->next;
        head->next = newHead->prev = NULL;
        free(head);
        head = newHead;
    }
}

void popAll() {
    if (!head) {
        return;
    }
    else {
        curr = head;
        while (curr) {
            popHead();
            curr = curr->next;
        }
    }
}