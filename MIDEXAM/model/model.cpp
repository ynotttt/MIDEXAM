#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int day, year;
    char month[255], name[255];
    Node *next, *prev;
} *head, *tail, *curr;

Node *createNode(char *name, int day, char *month, int year)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->day = day;
    strcpy(temp->month, month);
    temp->year = year;
    temp->next = temp->prev = NULL;
    return temp;
}