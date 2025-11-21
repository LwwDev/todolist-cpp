#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//includes necessary libs


vector<string> tasks; // creats array
const string FILE_NAME = "tasks.txt"; //sets file name

void loadTasks() { // function
    ifstream file(FILE_NAME); // ifstream not sure what this does
    if (!file.is_open()) return; // if file is not open return 
    string line; // not surewhat this does
    while (getline(file, line)) { // not sure
        tasks.push_back(line); // not sure
    }
    file.close(); // not sure
}

void saveTasks() { // not sure what this function does
    ofstream file(FILE_NAME);
    for (auto &t : tasks) file << t << "\n";
    file.close(); // still dont know
}

void listTasks() {
    if (tasks.empty()) {
        cout << "No tasks yet.\n";
        return;
    }
    cout << "\nYour tasks:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << "\n";
    }
    cout << "\n";
}

void addTask() {
    cout << "Enter task: ";
    string task;
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added!\n";
}

void removeTask() {
    listTasks();
    if (tasks.empty()) return;

    cout << "Enter the task number to remove: ";
    int num;
    cin >> num;
    if (num < 1 || num > tasks.size()) {
        cout << "Invalid number.\n";
        return;
    }
    tasks.erase(tasks.begin() + (num - 1));
    cout << "Task removed!\n";
}

int main() {
    loadTasks();

    while (true) {
        cout << "\n===== TO-DO LIST =====\n";
        cout << "1. Show tasks\n";
        cout << "2. Add task\n";
        cout << "3. Remove task\n";
        cout << "4. Save & Exit\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: listTasks(); break;
            case 2: addTask(); break;
            case 3: removeTask(); break;
            case 4: saveTasks(); cout << "Saved. Bye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
