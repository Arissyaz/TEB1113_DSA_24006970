/*
ID : 24006970
Name: Arissya Zahiera Binti Zulazman
Group: G1
Singly Linked List
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
        Node* head;

public:
        SinglyLinkedList() {
        head = nullptr;
    }

    void addNode(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        cout << "List: ";
        if (temp == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteByValue(int val) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Deleted successfully" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found" << endl;
        }
        else {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Deleted successfully" << endl;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice;
    int value;

    do {
        cout << "Singly Linked List Menu" << endl;
        cout << "1. Add node" << endl;
        cout << "2. Display list" << endl;
        cout << "3. Delete node by value" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            list.addNode(value);
            break;
        case 2:
            list.display();
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteByValue(value);
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 4);

    return 0;
}
