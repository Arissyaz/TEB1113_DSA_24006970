/*
ID : 24006970
Name: Arissya Zahiera Binti Zulazman
Group: G1
Circular Singly Linked List with String Values
*/
#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void addNode(string val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;  
        }
        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        if (tail == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }

        Node* temp = tail->next;
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(Back to start)" << endl;
    }

    void deleteByValue(string val) {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* curr = tail->next;
        Node* prev = tail;

        do {
            if (curr->data == val) {
                if (curr == tail && curr == tail->next) { // Only one node
                    delete curr;
                    tail = nullptr;
                }
                else {
                    prev->next = curr->next;
                    if (curr == tail) {
                        tail = prev;
                    }
                    delete curr;
                }
                cout << "Deleted successfully" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);

        cout << "Value not found" << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice;
    string value;

    do {
        cout << "Circular Singly Linked List Menu" << endl;
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
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 4);

    return 0;
}
