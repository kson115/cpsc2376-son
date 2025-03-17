#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <memory>   // smart pointer

class Employee 
{
protected:
    std::string name;
    int id;

public:
    Employee(std::string name, int id) : name(name), id(id) {}

    virtual ~Employee() = default;
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const 
    {
        std::cout << "ID: " << id << ", Name: " << name << ", Type: ";
    }
};

class SalariedEmployee : public Employee 
{
private:
    double monthlySalary;

public:
    SalariedEmployee(std::string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {}

    double calculateSalary() const override 
    {
        return monthlySalary;
    }

    void displayInfo() const override 
    {
        Employee::displayInfo();
        std::cout << "Salaried, Monthly Salary: $" << std::fixed << std::setprecision(2)
            << monthlySalary << std::endl;
    }
};

class HourlyEmployee : public Employee 
{
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override 
    {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override 
    {
        Employee::displayInfo();
        std::cout << "Hourly, Hours Worked: " << hoursWorked
            << ", Hourly Rate: $" << std::fixed << std::setprecision(2) << hourlyRate
            << ", Salary: $" << calculateSalary() << std::endl;
    }
};

class CommissionEmployee : public Employee 
{
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}

    double calculateSalary() const override 
    {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override 
    {
        Employee::displayInfo();
        std::cout << "Commission, Base Salary: $" << std::fixed << std::setprecision(2) << baseSalary
            << ", Sales: $" << salesAmount
            << ", Commission Rate: " << commissionRate * 100 << "%"
            << ", Salary: $" << calculateSalary() << std::endl;
    }
};

int main() 
{
    std::vector<std::unique_ptr<Employee>> employees;
    std::ifstream file("employees.txt");

    if (!file) 
    {
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        std::istringstream ss(line);
        std::string type, name;
        int id;
        ss >> type >> id >> name;

        if (type == "Salaried") 
        {
            double monthlySalary;
            ss >> monthlySalary;
            employees.push_back(std::make_unique<SalariedEmployee>(name, id, monthlySalary));
        }
        else if (type == "Hourly") 
        {
            double hourlyRate;
            int hoursWorked;
            ss >> hourlyRate >> hoursWorked;
            employees.push_back(std::make_unique<HourlyEmployee>(name, id, hourlyRate, hoursWorked));
        }
        else if (type == "Commission") 
        {
            double baseSalary, salesAmount, commissionRate;
            ss >> baseSalary >> salesAmount >> commissionRate;
            employees.push_back(std::make_unique<CommissionEmployee>(name, id, baseSalary, salesAmount, commissionRate));
        }
        else 
        {
            std::cerr << "Error: Invalid employee type in file.\n";
        }
    }

    file.close();

    // Display employee details and salaries
    for (const auto& employee : employees) 
    {
        employee->displayInfo();
    }

    return 0;
}

//  Ai-created template with modification
