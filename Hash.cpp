#include <iostream>
#include <string>
#include "Card.h"
#include "Hash.h"

#define LENGTH 5
using namespace KanbanBoardCard;

struct Node 
{
    Card* value; 
    Node* next;   
};

struct List 
{
    Node* first;  
};

struct Hashtable 
{
    List* table[LENGTH];  
};

int hashFunction(string key) 
{
    return key.length() % LENGTH;
}

void Add(Hashtable* hashtable, string key, Card* value) 
{
    int index = hashFunction(key);

    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (hashtable->table[index] == nullptr) 
    {
        hashtable->table[index] = new List;
        hashtable->table[index]->first = newNode;
    }
    else 
    {
        newNode->next = hashtable->table[index]->first;
        hashtable->table[index]->first = newNode;
    }
}

void Remove(Hashtable* hashtable, string key) 
{
    int index = hashFunction(key);

    if (hashtable->table[index] == nullptr || hashtable->table[index]->first == nullptr) 
    {
        return;
    }

    Node* current = hashtable->table[index]->first;
    Node* prev = nullptr;

    while (current != nullptr && KanbanBoardCard::GetId(current->value) != key) 
    {
        prev = current;
        current = current->next;
    }

  
    if (current == nullptr) 
    {
        return;
    }
 
    if (prev == nullptr) 
    {
     
        hashtable->table[index]->first = current->next;
    }
    else 
    {
        prev->next = current->next;
    }

    delete current;
}

Card* Get(Hashtable* hashtable, string key) {
    int index = hashFunction(key);

    Node* current = hashtable->table[index]->first;

    while (current != nullptr && KanbanBoardCard::GetId(current->value) != key) {
        current = current->next;
    }

    if (current == nullptr) {
        return nullptr;
    }

    return current->value;
}

void DestroyHashtable(Hashtable* hashtable)
{
    for (int i = 0; i < LENGTH; ++i)
    {
        Node* current = hashtable->table[i] ? hashtable->table[i]->first : nullptr;
        while (current != nullptr)
        {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        delete hashtable->table[i];
    }
    delete hashtable;
}