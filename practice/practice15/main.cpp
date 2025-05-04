/*#include <iostream>
#include <vector>
#include <memory>

class GradeObserver {
public:
    virtual void update(float grade) = 0;
    virtual ~GradeObserver() = default;
};

class AverageUpdater : public GradeObserver {
private:
    float sum = 0;
    int count = 0;

public:
    void update(float grade) override {
        sum += grade;
        count++;
        std::cout << "Running average: " << (sum / count) << std::endl;
    }
};

class GradeNotifier : public GradeObserver {
public:
    void update(float grade) override {
        if (grade < 60) {
            std::cout << "Email sent to student@example.com: Your grade dropped below 60%!" << std::endl;
        }
    }
};

class GradeBook {
private:
    std::vector<std::shared_ptr<GradeObserver>> observers;
    float grade;

public:
    void addObserver(std::shared_ptr<GradeObserver> observer) {
        observers.push_back(observer);
    }

    void setGrade(float newGrade) {
        grade = newGrade;
        for (auto& obs : observers) {
            obs->update(grade);
        }
    }
};

int main() {
    GradeBook gradeBook;
    auto avgUpdater = std::make_shared<AverageUpdater>();
    auto notifier = std::make_shared<GradeNotifier>();

    gradeBook.addObserver(avgUpdater);
    gradeBook.addObserver(notifier);

    gradeBook.setGrade(85);
    gradeBook.setGrade(55);

    return 0;
}*/

#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

class TextFilter {
public:
    virtual std::string applyFilter(const std::string& text) = 0;
    virtual ~TextFilter() = default;
};

class ReverseFilter : public TextFilter {
public:
    std::string applyFilter(const std::string& text) override {
        std::string reversed = text;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }
};

class UppercaseFilter : public TextFilter {
public:
    std::string applyFilter(const std::string& text) override {
        std::string upper = text;
        std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
        return upper;
    }
};
// Allow the user to select and apply filters dynamically
int main() {
    std::unique_ptr<TextFilter> filter;
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    filter = std::make_unique<ReverseFilter>();
    std::cout << "Reversed: " << filter->applyFilter(input) << std::endl;

    filter = std::make_unique<UppercaseFilter>();
    std::cout << "Uppercase: " << filter->applyFilter(input) << std::endl;
    return 0;
}

