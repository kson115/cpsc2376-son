#include <iostream>
#include <vector>
#include <memory>

class GradeObserver 
{
public:
    virtual void update(float grade) = 0;
    virtual ~GradeObserver() = default;
};

class AverageUpdater : public GradeObserver 
{
private:
    float sum = 0;
    int count = 0;

public:
    void update(float grade) override 
    {
        sum += grade;
        count++;
        std::cout << "Running average: " << (sum / count) << std::endl;
    }
};

class GradeNotifier : public GradeObserver 
{
public:
    void update(float grade) override 
    {
        if (grade < 80) 
        {
            std::cout << "Email sent to student@example.com: Your grade dropped below 90%!" << std::endl;
        }
    }
};

class GradeBook 
{
private:
    std::vector<std::shared_ptr<GradeObserver>> observers;
    float grade;

public:
    void addObserver(std::shared_ptr<GradeObserver> observer) 
    {
        observers.push_back(observer);
    }

    void setGrade(float newGrade) 
    {
        grade = newGrade;
        for (auto& obs : observers) 
        {
            obs->update(grade);
        }
    }
};

int main() 
{
    GradeBook gradeBook;
    auto avgUpdater = std::make_shared<AverageUpdater>();
    auto notifier = std::make_shared<GradeNotifier>();

    gradeBook.addObserver(avgUpdater);
    gradeBook.addObserver(notifier);

    gradeBook.setGrade(85);
    gradeBook.setGrade(75);

    return 0;
}

//AI-generated template