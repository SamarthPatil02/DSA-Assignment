//SAMARTH PATIL
//Roll no:23574
//batch:S4
//DSAL
// Assignment 10
//..................................................................................................
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Student {
    string rollNumber;
    string name;
    string division;
    string address;
};

vector<Student> loadData(const string& filename) {
    vector<Student> students;
    ifstream file(filename.c_str());
    if (!file) return students;

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        Student student;
        getline(ss, student.rollNumber, ',');
        getline(ss, student.name, ',');
        getline(ss, student.division, ',');
        getline(ss, student.address);
        students.push_back(student);
    }

    file.close();
    return students;
}

void saveData(const string& filename, const vector<Student>& students) {
    ofstream file(filename.c_str());
    for (size_t i = 0; i < students.size(); ++i) {
        file << students[i].rollNumber << ","
             << students[i].name << ","
             << students[i].division << ","
             << students[i].address << endl;
    }
    file.close();
}

void addStudent(const string& filename) {
    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    vector<Student> students = loadData(filename);
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].rollNumber == student.rollNumber) {
            cout << "Student with this roll number already exists.\n";
            return;
        }
    }

    students.push_back(student);
    saveData(filename, students);
    cout << "Student added successfully.\n";
}

void deleteStudent(const string& filename) {
    string rollNumber;
    cout << "Enter Roll Number of the student to delete: ";
    cin >> rollNumber;

    vector<Student> students = loadData(filename);
    vector<Student> updatedStudents;

    bool found = false;
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].rollNumber != rollNumber) {
            updatedStudents.push_back(students[i]);
        } else {
            found = true;
        }
    }

    if (found) {
        saveData(filename, updatedStudents);
        cout << "Student deleted successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

void displayStudent(const string& filename) {
    string rollNumber;
    cout << "Enter Roll Number to search: ";
    cin >> rollNumber;

    vector<Student> students = loadData(filename);
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].rollNumber == rollNumber) {
            cout << "Student Found!\n";
            cout << "Roll Number: " << students[i].rollNumber << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Division: " << students[i].division << endl;
            cout << "Address: " << students[i].address << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void mainMenu(const string& filename) {
    while (true) {
        cout << "\nStudent Database Management\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Student Information\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                deleteStudent(filename);
                break;
            case 3:
                displayStudent(filename);
                break;
            case 4:
                cout << "Exiting...\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    const string filename = "student_database.txt";
    mainMenu(filename);
    return 0;
}
