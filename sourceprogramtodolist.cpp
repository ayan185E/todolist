#include <iostream>
#include <string>
#include <vector>
using namespace std;
class todolist {
public:
int taskcount;
vector<string> tasks;//add task in todo list
void addtask(string task) {
    tasks.push_back(task);
    taskcount++;
}//display your todo list
void displaytasks() {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
    } else {
        cout << "\nCurrent tasks:\n";
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}//mark done item in todo list
void markdoneitem(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        cout << "Task " << index << " marked as done: " << tasks[index - 1] << endl;
        string donetask = "[Done] " + tasks[index - 1];
        tasks[index - 1] = donetask;
        taskcount--;
        cout << "Task mark done....\n";
    }
}//deleting todo list
void removetask(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        taskcount--;
        cout << "Task removed successfully.\n";
    }
}
};
int main()
{ 
    int choice;
    todolist mylist;
    cout << "Welcome to the To-Do List Application!\n";
    mylist.taskcount = 0;
    do{
        cout <<"\nMenu:\n";
        cout <<"1. Add Task\n";
        cout <<"2. Display Tasks\n";
        cout <<"3. Remove Task\n";
        cout <<"4. Mark done item\n";
        cout <<"5. Turn off the prograan";
        cout <<"\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                getline(cin, task);
                mylist.addtask(task);
                cout << "Task added successfully.\n";
                break;
            }
            case 2:
                mylist.displaytasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                mylist.removetask(taskNumber);
                break;
            }
            case 4:
                cout << "Enter the task number to mark as done: ";
                int doneTaskNumber;
                cin >> doneTaskNumber;
                mylist.markdoneitem(doneTaskNumber);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    }while (choice != 5);
    
    return 0;
    
    
}
    
