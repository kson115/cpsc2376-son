
#include <iostream>
#include <list>
#include <string>

void menu() 
{
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Remove Task" << std::endl;
    std::cout << "3. Show Tasks" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void addTask(std::list<std::string>& tasks) 
{
    std::string task;
    std::cout << "Enter task: ";
    std::cin.ignore();
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added!" << std::endl;
}

void showTasks(const std::list<std::string>& tasks)
{
    int taskNumber = 1;
    std::cout << "Tasks:" << std::endl;
    for (const auto& task : tasks)
    {
        std::cout << taskNumber++ << ". " << task << std::endl;
    }
}

void removeTask(std::list<std::string>& tasks) 
{
    int taskNumber;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) 
    {
        auto it = tasks.begin();
        std::advance(it, taskNumber - 1);
        tasks.erase(it);
        std::cout << "Task removed!" << std::endl;
    }
    else 
    {
        std::cout << "Invalid task number!" << std::endl;
    }
}

int main() 
{
    std::list<std::string> tasks;
    int choice;

    while (true) 
    {
        menu();
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            addTask(tasks);
            break;
        case 2:
            removeTask(tasks);
            break;
        case 3:
            showTasks(tasks);
            break;
        case 4:
            std::cout << "Exit" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please choose 1 to 4." << std::endl;
        }
    }
    return 0;
}

// This templated was created by Ai and modified
// Please comment out both problem1a.cpp and program2a.cpp, then run this program