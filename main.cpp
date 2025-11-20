#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> tasks;
const string FILE_NAME = "tasks.txt";

void loadTasks() {
    ifstream file(FILE_NAME);
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        tasks.push_back(line);
    }
    file.close();
}

void saveTasks() {
    ofstream file(FILE_NAME);
    for (auto &t : tasks) file << t << "\n";
    file.close();
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
