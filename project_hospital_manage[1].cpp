#include <iostream>
#include <string>

// Structure for patient details
struct Patient {
    int id;
    std::string name;
    int priority; // Higher priority patients should be treated first
    Patient* next;
    
    Patient(int id_, std::string name_, int priority_) : id(id_), name(name_), priority(priority_), next(NULL) {}
};

// Queue class using linked list
class Queue {
private:
    Patient* front;
    Patient* rear;
    
public:
    Queue() : front(NULL), rear(NULL) {}
    
    // Enqueue patient
    void enqueue(int id, std::string name, int priority) {
        Patient* newPatient = new Patient(id, name, priority);
        if (rear == NULL) {
            front = rear = newPatient;
        } else {
            rear->next = newPatient;
            rear = newPatient;
        }
    }

    // Dequeue patient
    void dequeue() {
        if (front == NULL) {
            std::cout << "Queue is empty!\n";
            return;
        }
        Patient* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Display the queue
    void display() {
        if (front == NULL) {
            std::cout << "Queue is empty!\n";
            return;
        }
        Patient* temp = front;
        while (temp != NULL) {
            std::cout << "Patient ID: " << temp->id << ", Name: " << temp->name << ", Priority: " << temp->priority << "\n";
            temp = temp->next;
        }
    }

    // Get front patient
    Patient* getFront() {
        return front;
    }
};

// Priority Queue class using linked list
class PriorityQueue {
private:
    Patient* head;

public:
    PriorityQueue() : head(NULL) {}
    
    // Enqueue patient based on priority
    void enqueue(int id, std::string name, int priority) {
        Patient* newPatient = new Patient(id, name, priority);
        if (head == NULL || head->priority < priority) {
            newPatient->next = head;
            head = newPatient;
        } else {
            Patient* temp = head;
            while (temp->next != NULL && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newPatient->next = temp->next;
            temp->next = newPatient;
        }
    }

    // Dequeue highest priority patient
    void dequeue() {
        if (head == NULL) {
            std::cout << "Priority queue is empty!\n";
            return;
        }
        Patient* temp = head;
        head = head->next;
        delete temp;
    }

    // Check if priority queue is empty
    bool isEmpty() {
        return head == NULL;
    }

    // Display the priority queue
    void display() {
        if (head == NULL) {
            std::cout << "Priority queue is empty!\n";
            return;
        }
        Patient* temp = head;
        while (temp != NULL) {
            std::cout << "Patient ID: " << temp->id << ", Name: " << temp->name << ", Priority: " << temp->priority << "\n";
            temp = temp->next;
        }
    }

    // Get front patient in priority queue
    Patient* getFront() {
        return head;
    }
};

// Hospital Management System class
class HospitalManagementSystem {
private:
    Queue regularQueue;
    PriorityQueue priorityQueue;
    int patientID;

public:
    HospitalManagementSystem() : patientID(1) {}

    // Register a patient
    void registerPatient(std::string name, int priority) {
        if (priority > 5) {
            priorityQueue.enqueue(patientID, name, priority);
            std::cout << "Patient " << name << " registered in priority queue with priority " << priority << ".\n";
        } else {
            regularQueue.enqueue(patientID, name, priority);
            std::cout << "Patient " << name << " registered in regular queue.\n";
        }
        patientID++;
    }

    // Treat a patient
    void treatPatient() {
        if (!priorityQueue.isEmpty()) {
            std::cout << "Treating priority patient: " << priorityQueue.getFront()->name << "\n";
            priorityQueue.dequeue();
        } else if (!regularQueue.isEmpty()) {
            std::cout << "Treating regular patient: " << regularQueue.getFront()->name << "\n";
            regularQueue.dequeue();
        } else {
            std::cout << "No patients to treat.\n";
        }
    }

    // Display all patients
    void displayPatients() {
        std::cout << "\nPriority Queue Patients:\n";
        priorityQueue.display();
        std::cout << "\nRegular Queue Patients:\n";
        regularQueue.display();
    }
};

// Main function
int main() {
    HospitalManagementSystem hospital;

    int choice;
    std::string name;
    int priority;

    do {
        std::cout << "\nHospital Management System\n";
        std::cout << "1. Register Patient\n";
        std::cout << "2. Treat Patient\n";
        std::cout << "3. Display Patients\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter patient name: ";
                std::cin >> name;
                std::cout << "Enter patient priority (1-10): ";
                std::cin >> priority;
                hospital.registerPatient(name, priority);
                break;
            case 2:
                hospital.treatPatient();
                break;
            case 3:
                hospital.displayPatients();
                break;
            case 4:
                std::cout << "Exiting the system.\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

