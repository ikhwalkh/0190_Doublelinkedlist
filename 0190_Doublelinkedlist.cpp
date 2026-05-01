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

          // Step 2: If node is at the beginning
        if (current == START)
        {
            START = current->next; // Step 3a
            if (START != NULL)
                START->prev = NULL; // Step 3b
        }
        else
        {
            // Step 4: Link previous node to next of current
            current->prev->next = current->next;

            // Step 5: Link next node to prev of current
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // Step 6: Delete node
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

     void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Start from first node as currentnode
        Node *currentnode = START;

        cout << "\nRecords in ascending order of roll number are:\n";
        while (currentnode != NULL)
        {
            // Step 2: Print roll no as currentnode->info
            cout << currentnode->no << " ";

            // Step 3: Move to next node
            currentnode = currentnode->next;
        }
        cout << endl;
    }

     void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Move to last node
        Node *currentnode = START;
        int i = 1;

        while (currentnode->next != NULL)
        {
            currentnode = currentnode->next;
            i++;
        }

        // Step 2: Traverse backward
        cout << "\nRecords in descending order of roll number are:\n";
        while (currentnode != NULL)
        {
            cout << i << " " << currentnode->no << " " << endl;

            // Step 3: Move to previous node
            currentnode = currentnode->prev;
            i--;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse and search roll no
        while (current != NULL && current->no != rollNo)
        {
            current = current->next;
        }

        // Step 2: Output result
        if (current == NULL)
        {
            cout << "Record not found";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll number: " << current->no << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;
