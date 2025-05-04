#include <iostream>
#include <memory>

// Strategy Interface
class Strategy {
public:
    virtual void execute() const = 0;
    virtual ~Strategy() = default;
};

// Concrete Strategies
class Run : public Strategy {
public:
    void execute() const override {
        std::cout << "Running!\n";
    }
};

class Hide : public Strategy {
public:
    void execute() const override {
        std::cout << "Hiding!\n";
    }
};

// Agent class that holds a Strategy
class Agent {
    std::unique_ptr<Strategy> strategy;
public:
    void setStrategy(std::unique_ptr<Strategy> s) {
        strategy = std::move(s);
    }
    void act() const {
        if (strategy) strategy->execute();
    }
};

// Main function to test the Strategy Pattern
int main() {
    
    Agent a;
    a.setStrategy(std::make_unique<Hide>());
    a.act();
    

    return 0;
}
