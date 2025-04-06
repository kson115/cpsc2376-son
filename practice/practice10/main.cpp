#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

class Shape 
{
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
};

class Rectangle : public Shape 
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override 
    {
        return width * height;
    }
};

class Circle : public Shape 
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override 
    {
        return 3.14159 * radius * radius;
    }
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) 
{
    for (const auto& shape : shapes) 
    {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

int main() 
{
    std::ifstream inputFile("shapes.txt");
    if (!inputFile) 
    {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(inputFile, line)) 
    {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == "rectangle") 
        {
            double width, height;
            iss >> width >> height;
            shapes.push_back(std::make_unique<Rectangle>(width, height));
        }
        else if (shapeType == "circle") 
        {
            double radius;
            iss >> radius;
            shapes.push_back(std::make_unique<Circle>(radius));
        }
        else 
        {
            std::cerr << "Error: Unknown shape type \"" << shapeType << "\"." << std::endl;
        }
    }

    inputFile.close();
    printAllAreas(shapes);
    return 0;
}

// AI- created template with modifications
// #include <iomanip>
// std::cout << "Area: " << shape->getArea() << std::endl; is used instead of 
// std::cout << Area: " << std::fixed << std::setprecision(4) << shape->getArea() << std::endl; 
// to make the output consistent with the assignment output 
// the retangular area output 40 16 vs  40.0000, 16.0000 