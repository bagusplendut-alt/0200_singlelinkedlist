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

        void traverse()
        {
            if (listEmpty())
            {
                cout << "\nList Kosong\n";
            }
            else
            {
                cout << "Data didalam list adalah:\n";
                Node *currentNode = START;
                while (currentNode != NULL)
                {
                    cout << currentNode->noMhs << endl;
                    currentNode = currentNode->next;
                }
                cout << endl;
            }
            
        }

    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;
    do
    {
    {
        cout << endl
             << "menu";
        cout << endl
             << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data di dalam list" << endl;
        cout << "4. Menampilkan semua data di dalam list secara terbalik" << endl;
        cout << "5. mencari data dalam list" << endl;
        cout << "6. keluar" << endl;
        cout << endl
             << "masukan pilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            mhs.addNode();
        }
        case '2':
        {
            if (mhs.listEmpity())
            {
                cout << endl
                     << "List Kosong" << endl;
                break;     
            }
            cout << endl;
                 << "\nMasukan no mahasiswa yang akan di hapus : ";
                 cin >> nim;
            if (mhs.delNode(nim) == false)
                cout << endl
                     << "Data tidak di temukan" << endl;
            else
                cout << endl
                     << "Data dengan nomor mahasiswa " << nim
                     << "berhasil di hapus" << endl;
        }
        break;
        case '3';
        {
            mhs.traverse();
        }
        break;
        case '4':
        {
        if (mhs.listEmpty() == true)
        {
            cout << "\nList Kosong\n";
            break;
        }
        Node *previous, *current;
        cout << endl
            << "Masukkan no mahasiswa yang dicari : ";
        cin >> nim;
        if (mhs.Search(nim, &previous, &current) == false)
            cout << endl
                << "Data tidak ditemukan" << endl;
        else
        {
            cout << endl
                << "Data ditemukan" << endl;
            cout << "\nNo Mahasiswa: " << current->noMhs << endl;
            cout << "\n";
        }
        }
        break;
        case '5':
        {
        }
        break;
        default:
        {
            cout << "Pilihan salah !." << endl;
        }
        break;
        }
    } while (ch != '5');

}