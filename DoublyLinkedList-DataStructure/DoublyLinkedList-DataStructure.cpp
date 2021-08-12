#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }

    //Insert node at start
    void insertBegin(int data) {
        Node* temp = new Node;
        if (head == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
            temp->data = data;
            head = temp;
        }
        else
        {
            temp->data = data;
            temp->prev = NULL;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        cout<<"\nNode inserted\n";
    }

    //Insert node at last
    void insertLast(int data)
    {
        Node* temp = new Node;
        temp->data = data;

        if (head == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
            cout << temp->data << " is inserted \n";
        }
        else
        {

            Node* ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
            temp->next = NULL;
            cout << temp->data << " is inserted \n";
        }
    }

    // insert at index
    void insertAtIndex(int data, int index) {
        Node* temp = new Node;
        temp->data = data;
        Node* ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "\ncan't insert\n";
                return;
            }
        }
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
        ptr->next->prev = temp;
        cout << temp->data << " is inserted \n";

    }


    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteBegin() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        else if (head->next == NULL) {
            cout << head->data << " is removed." << endl;
            delete head;
            
        }
        else {
            cout << head->data << " is removed." << endl;
            head = head->next;
            head->prev = NULL;
        }
    }

    void deleteLast() {
        struct Node* ptr, * ptr1;
        ptr1 = NULL;
        if (head == NULL)
        {
            cout << "\nlist is empty\n";
        }
        else if (head->next == NULL)
        {
            head = NULL;
            cout << "Only node of the list deleted \n";
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->prev->next = NULL;
            ptr = NULL;
            delete ptr;
            cout << "\nDeleted Node from the last\n";
        }
    }


    void deleteAtIndex(int index) {
        Node* temp;
        Node* ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "\ncan't delete\n";
                return;
            }
        }
        temp= ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        delete temp;
        cout << "\nDeleted node at index  \t " << index << endl;
    }


    void search(int data)
    {
        struct Node* ptr;
        int i = 0;
        ptr = head;
        if (ptr == NULL)
        {
            cout << "\nEmpty List\n";
        }
        else
        {
            while (ptr != NULL)
            {
                if (ptr->data == data)
                {
                    cout << "item found at location \t " << i << endl;
                    return;

                }
                i++;
                ptr = ptr->next;
            }

            cout << "Item not found\n";
        }

    }

};




int main()
{
    DoublyLinkedList doublyList;



    int choice = 0;
    int data, index;
    while (choice != 9)
    {
        cout << "\n\n*********Main Menu*********\n";
        cout << "\nChoose one option from the following list ...\n";
        cout << "\n===============================================\n";
        cout << "\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n";
        cout << "\nEnter your choice?\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Please enter the data you want to insert at the beginning:\t";
            cin >> data;
            doublyList.insertBegin(data);
            break;
        case 2:
            cout << "Please enter the data you want to insert at the last:\t";
            cin >> data;
            doublyList.insertLast(data);
            break;
        case 3:
            cout << "Please enter the data you want to insert :\t";
            cin >> data;
            cout << "\nEnter the location after which you want to insert \t";
            cin >> index;
            doublyList.insertAtIndex(data, index);
            break;
        case 4:
            doublyList.deleteBegin();
            break;
        case 5:
            doublyList.deleteLast();
            break;
        case 6:
            cout << "\nEnter the location which you want to delete \t";
            cin >> index;
            doublyList.deleteAtIndex(index);
            break;
        case 7:
            cout << "Please enter the data you want to search about :\t";
            cin >> data;
            doublyList.search(data);
            break;
        case 8:
            doublyList.display();
            break;
        case 9:
            break;
        default:
            cout << "Please enter valid choice..\n";
        }
    }



    system("pause>0");
}

