#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Task{
    string description;
    bool completed;
};

void addTask(vector<Task> &tasks, const string &description){
    Task newTask = {description,false};
    tasks.push_back(newTask);
    cout<<"Task added successfully.\n";
}

void viewTasks(const vector<Task> &tasks){
    if(tasks.empty()){
        cout<<"No tasks available.\n";
        return;
    }
    cout<<"\nTasks:\n";
    for(size_t i=0;i<tasks.size();++i){
        cout<<i+1<<". "<<tasks[i].description;
        if(tasks[i].completed){
            cout<<" [Completed]";
        }
        cout<<endl;
    }
}

void markTaskCompleted(vector<Task> &tasks, int index){
    if(index<0 || index>=tasks.size()){
        cout<<"Invalid task number.\n";
        return;
    }
    tasks[index].completed = true;
    cout<< "Task marked as completed.\n";
}

void removeTask(vector<Task> &tasks,int index){
    if(index < 0 || index>= tasks.size()){
        cout<<"Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + index);
    cout<<"Task removed successfully.\n";
}

int main(){
    vector<Task> tasks;
    int choice;
    string description;
    int index;

    while(true){
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch(choice){
            case 1:
            cout<<"Enter task Description: ";
            getline(cin,description);
            addTask(tasks,description);
            break;
            case 2:
            viewTasks(tasks);
            break;
            case 3:
            cout<<"Enter the task number to mark as completed: ";
            cin>>index;
            markTaskCompleted(tasks,index-1);
            break;
            case 4:
            cout<<"Enter the task number to remove: ";
            cin>>index;
            removeTask(tasks,index-1);
            break;
            case 5:
            cout<<"Exiting.....\n";
            return 0;
            default:
            cout<<"Invalid choice.Please try again.\n";


        }
    }
}
