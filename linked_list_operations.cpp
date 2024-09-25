#include <iostream>
#include <string>

using namespace std;

struct Task {
    int taskID;
    string description;
    int priority;
    Task* next;
};

// Function to add a new task at the beginning (simple insertion)
void addTask(Task*& head, int id, string desc, int priority) {
    Task* newTask = new Task();
    newTask->taskID = id;
    newTask->description = desc;
    newTask->priority = priority;
    newTask->next = head;
    head = newTask;
    cout << "Task added successfully!\n";
}

// Function to view all tasks
void viewTasks(Task* head) {
    if (head == NULL) {
        cout << "No tasks in the list.\n";
        return;
    }
    Task* current = head;
    while (current != NULL) {
        cout << "Task ID: " << current->taskID << ", Description: " << current->description << ", Priority: " << current->priority << endl;
        current = current->next;
    }
}

// Function to remove the first task (highest priority task)
void removeFirstTask(Task*& head) {
    if (head == NULL) {
        cout << "No tasks to remove.\n";
        return;
    }
    Task* temp = head;
    head = head->next;
    cout << "Removed task with ID: " << temp->taskID << endl;
    delete temp;
}

// Function to remove a task by its task ID
void removeTaskByID(Task*& head, int id) {
    if (head == NULL) {
        cout << "No tasks to remove.\n";
        return;
    }
    if (head->taskID == id) {
        Task* temp = head;
        head = head->next;
        cout << "Removed task with ID: " << temp->taskID << endl;
        delete temp;
        return;
    }
    Task* current = head;
    while (current->next != NULL && current->next->taskID != id) {
        current = current->next;
    }
    if (current->next == NULL) {
        cout << "Task with ID: " << id << " not found.\n";
    } else {
        Task* temp = current->next;
        current->next = current->next->next;
        cout << "Removed task with ID: " << temp->taskID << endl;
        delete temp;
    }
}

// Function to display the menu
void menu() {
    Task* head = NULL; // Initialize an empty task list
    int choice, id, priority;
    string description;

    while (true) {
        cout << "\nTask Management System Menu:\n";
        cout << "1. Add a new task\n";
        cout << "2. View all tasks\n";
        cout << "3. Remove the first task\n";
        cout << "4. Remove a task by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter task priority: ";
                cin >> priority;
                addTask(head, id, description, priority);
                break;
            case 2:
                viewTasks(head);
                break;
            case 3:
                removeFirstTask(head);
                break;
            case 4:
                cout << "Enter task ID to remove: ";
                cin >> id;
                removeTaskByID(head, id);
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}

