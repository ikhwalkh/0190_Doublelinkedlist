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

     void addNode()
    {
        int nim;
        cout << "Enter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newnode = new Node();

        // Step 2: Assign value to the data field
        newnode->no = nim;

        // If list is empty or inserting at 1st is empty or not in sorted
        if (START == NULL || nim <= START->no)
        {
            if (START != NULL && nim == START->no)
            {
                cout << "\nDuplicate roll numbers not allowed" << endl;
                return;
            }

            // Step 3: newnode.next = START
            newnode->next = START;

            // Step 4: START.prev = newnode (if START exists)
            if (START != NULL)
                START->prev = newnode;

            // Step 5: newnode.prev = NULL
            newnode->prev = NULL;

            // Step 6: START = newnode
            START = newnode;
            return;
        }

         // Step 7: Advance position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->no < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->no)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // Step 8: Insert between current and current->next
        Node *nextnode = current->next;
        newnode->next = nextnode;   // Step 9
        newnode->prev = current;    // Step 10

        if (nextnode != NULL)
            nextnode->prev = newnode; // Step 11

        current->next = newnode;      // Step 12
    }

     void deleteNode()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

        Node *current = START;

         // Step 1: Traverse the list to find the node
        while (current != NULL && current->no != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }