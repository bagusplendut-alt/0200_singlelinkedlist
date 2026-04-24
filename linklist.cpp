#include <iostream>
using namespace std;

class Node
{
    public:
        int noMHS;
        Node *next;
};

class linklist
{
    Node *START;
public:
    linklist()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nmasukan nomor mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMHS = nim;

        if (START == NULL || nim <= START->noMHS)
        {
            if ((START != NULL) && (nim == START->noMHS))
            {
            cout << "\nDuplikasi noMHS tidak di ijinkan\n";
            return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;

            Node *previous = START;
            Node *current = START;
            while ((current != NULL) && (nim >= current->noMHS))
            {
            if (nim == current->noMHS)
            {
                cout << "\nDuplikasi noMHS tidak di ijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
            }

        nodeBaru->next = current;
        previous->next = nodeBaru;
        }

        bool listEmpty()
        {
            return (START == NULL);
        }

        bool Search(int nim, Nodeprevious, Node current)
        {
            *previous = START;
            *current = START;

            while ((current != NULL) && (nim != (*current)->noMhs))
            {
                *previous = current;
                *current = (current)->next;
            }
            return (*current != NULL);
        }

        bool delNode(int nim)
        {
            Node *current, *previous;
            if (!Search(nim, &previous, &current))
                return false;

            if (current == START)
                START = START->next;
            else
                previous->next = current->;
            delete current;
            return true;
        }
