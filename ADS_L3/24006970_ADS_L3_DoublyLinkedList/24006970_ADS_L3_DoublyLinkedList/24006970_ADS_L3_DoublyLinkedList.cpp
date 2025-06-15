/*
ID : 24006970
Name: Arissya Zahiera Binti Zulazman
Group: G1
Doubly Linked List
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
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
            newNode->prev = temp;
        }
    }

    void displayForward() {
        Node* temp = head;
        cout << "List (forward): ";
        if (temp == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteByValue(int val) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        // Deleting head
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete toDelete;
            cout << "Deleted successfully" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found" << endl;
            return;
        }

        // Deleting in between or at end
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Deleted successfully" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value;

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
            list.displayForward();
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
