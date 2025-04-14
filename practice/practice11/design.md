
A lightweight tool to manage board games, customers, and loans at a local café.
This program helps a local board game café:

🔑 Nouns → Classes
Game: name, available copies
Customer: name, ID
Loan: links Game + Customer + due date
LendingSystem: manages all of the above

🔨 Verbs → Methods
Add game
List games
Check out game
Return game
List current loans

🧩 LendingSystem.h
#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

class Game {
public:
    Game(const std::string& name, int totalCopies);
    
    std::string getName() const;
    int getAvailableCopies() const;
    void increaseCopies(int count);
    bool decreaseCopies(); // returns false if no copies left

private:
    std::string name;
    int availableCopies;
};

class Customer {
public:
    Customer(const std::string& name, int id);
    
    std::string getName() const;
    int getId() const;

private:
    std::string name;
    int id;
};

class Loan {
public:
    Loan(std::shared_ptr<Game> game, std::shared_ptr<Customer> customer, const std::string& dueDate);
    
    std::shared_ptr<Game> getGame() const;
    std::shared_ptr<Customer> getCustomer() const;
    std::string getDueDate() const;

private:
    std::shared_ptr<Game> game;
    std::shared_ptr<Customer> customer;
    std::string dueDate;
};

class LendingSystem {
public:
    void addGame(const std::string& name, int totalCopies);
    void addCustomer(const std::string& name, int id);
    
    bool checkOutGame(const std::string& gameName, int customerId, const std::string& dueDate);
    bool returnGame(const std::string& gameName, int customerId);
    
    std::vector<std::shared_ptr<Game>> listGames() const;
    std::vector<std::shared_ptr<Loan>> listLoans() const;

private:
    std::map<std::string, std::shared_ptr<Game>> games;
    std::map<int, std::shared_ptr<Customer>> customers;
    std::vector<std::shared_ptr<Loan>> activeLoans;
};


     ```markdown
     [Link to design.md](raw.githubusercontent.com/kson115/cpsc2376-son/5eed4e797bb26c0d56a09b9007c6f788aaf406f1/practice/practice11/design.md)
     ```

📊 Class Diagram (Mermaid)

classDiagram
    class Game {
        - string name
        - int availableCopies
        + getName() string
        + getAvailableCopies() int
        + increaseCopies(int)
        + decreaseCopies() bool
    }

    class Customer {
        - string name
        - int id
        + getName() string
        + getId() int
    }

    class Loan {
        - Game* game
        - Customer* customer
        - string dueDate
        + getGame() Game*
        + getCustomer() Customer*
        + getDueDate() string
    }

    class LendingSystem {
        - map<string, Game*> games
        - map<int, Customer*> customers
        - vector<Loan*> activeLoans
        + addGame(string, int)
        + addCustomer(string, int)
        + checkOutGame(string, int, string) bool
        + returnGame(string, int) bool
        + listGames() vector<Game*>
        + listLoans() vector<Loan*>
    }

    Game <-- Loan : borrowed
    Customer <-- Loan : borrowedBy
    LendingSystem --> Game : manages
    LendingSystem --> Customer : manages
    LendingSystem --> Loan : tracks













✅ Summary
🧾A clean spec
📦 Four modular C++ classes
🧠 Clear logic separation
📐 A mermaid diagram for visual understanding

AI-created template with modifications
