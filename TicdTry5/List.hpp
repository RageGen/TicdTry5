#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class SLException : public exception {
public:
    static const int EMPTY_LIST = 0;
    static const int OUT_OF_INDEX = 1;

    SLException(const int n, char* msg) :exception(msg) {
        cout << "Exception - " << n << endl;
    }
};
struct Node
{
    int data;
    Node* next;
};
class SingleList
{
    Node* top;
    int size;
public:
    SingleList() { top = NULL; size = 0; }
    Node* GetTop() { return top; }
    int GetSize() { return size; };
    void AddItem(int);
    void DeleteItem(int);
    bool IsItem(int);
    bool IsEmpty();
    void PrintList();
    void PrintListRecurrently(Node*);
    void DeleteList(Node*);
};
void InputFile(const char* c);