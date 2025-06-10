/*
ID: 24006970
Name: Arissya Zahiera Binti Zulazman
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    struct student { // structer variable name is student
        int numid;
        string name;
        string contact; //not uding int because we do not need to do calculation or math
        string email;
    }; // structure variable name can also be written here

    student stdarray[5];

    for (int i = 0; i < 5; i++) {
        cout << "Student " << i+1 << "\n";
        cout << "Insert student name: ";
        cin >> stdarray[i].name;
        cout << "Insert Student ID: ";
        cin >> stdarray[i].numid;
        cout << "Insert student contact number: ";
        cin >> stdarray[i].contact;
        cout << "Insert student email: ";
        cin >> stdarray[i].email;
    }
    for (int i = 0; i < 5; i++) {
        cout << "**************************\n";
        cout << "Student " << i+1 << endl;
        cout <<"Name: " << stdarray[i].name << endl;
        cout << "ID: " << stdarray[i].numid << endl;
        cout << "Contact: " << stdarray[i].contact << endl;
        cout << "Email: " << stdarray[i].email<< endl;
    }
}
 