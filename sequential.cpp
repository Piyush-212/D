#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int roll_no;
    char name[30];
    char division[5];
    char address[30];

public:
    void accept();
    void display();
    int getRollNo() const {
        return roll_no;
    }
};

void Student::accept() {
    cout << "\n Enter roll no:";
    cin >> roll_no;
    cout << "\n enter name:";
    cin >> name;
    cout << "\n Enter division:";
    cin >> division;
    cout << "\n Enter address:";
    cin>>address;}


void Student::display() {
    cout << "\n" << roll_no << "\t" << name << "\t" << division << "\t" << address;
}

void create() {
    Student s;
    int n;

    ofstream out("StudentData.txt", ios::app | ios::binary);

    cout << "\n How many records do you want to enter:";
    cin >> n;

    for (int i = 0; i < n; i++) {
        s.accept();
        out.write((char*)&s, sizeof(s));
    }

    out.close();
}

void search() {
    Student s;
    int n, flag = 0;
    ifstream in("StudentData.txt", ios::binary);

    cout << "\n Enter roll no to search:";
    cin >> n;
    while (in.read((char*)&s, sizeof(s))) {
        if (s.getRollNo() == n) {  
            flag = 1;
            cout << "\n Record found......";
            cout << "\n Rollno    Name   Division   Address";
            s.display();
            break;
        }
    }
    if (flag == 0) {
        cout << "\n Record not found....";
    }
    in.close();
}

void display() {
    Student s;
    ifstream in("StudentData.txt", ios::binary);

    cout << "\n Rollno   Name   Division    Address" << endl;

    while (in.read((char*)&s, sizeof(s))) {
        s.display();
    }

    in.close();
}

void addRecord() {
    Student s;
    ofstream out("StudentData.txt", ios::app | ios::binary);

    s.accept();
    out.write((char*)&s, sizeof(s));

    out.close();
    cout << "\n Record successfully added...";
}

int main() {
    int ch;
    do {
        cout << "\n Menu:";
        cout << "\n 1. Create database";
        cout << "\n 2. Display database";
        cout << "\n 3. Add Record";
        cout << "\n 4. Search Record";
        cout << "\n 5. Exit";

        cout << "\n Enter your choice:";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\n";
                create();
                break;

            case 2:
                cout << "\n";
                display();
                break;

            case 3:
                cout << "\n ";
                addRecord();
                break;

            case 4:
                cout << "\n";
                search();
                break;

            case 5:
                cout << "\n Successfully Exited.....";
                break;

            default:
                cout << "\n Invalid Choice. Please enter a valid option.";
        }

    } while (ch != 5);

    return 0;
}
