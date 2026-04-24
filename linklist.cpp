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
        START = NULL
    }

    void addNode()
    {
        int nim;
        cout << "\nmasukan nomor mahasiswa: ";
        cin >> nim;

        Node *nodebaru = new Node;
        nodebaru->noMHS = nim;

        if (START == NULL || nim <= START->noMHS)
        {
            if ((START != NULL) && (nim == START->noMHS))
        }

    }
}