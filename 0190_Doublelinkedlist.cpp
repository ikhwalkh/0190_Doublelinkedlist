//0190_Doublelinkedlist
#include <iostream>
#include <string>
using namespace std;

string response_std;

class Node
{
public:
    int no;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }