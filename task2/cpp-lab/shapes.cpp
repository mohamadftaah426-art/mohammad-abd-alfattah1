#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <cmath>

class Shape {
protected:
    std::string name;
public:
    Shape(const std::string& n) : name(n) {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() = default;
    
    void display() const {
        std::cout << name << ": area=" << area() 
                  << ", perimeter=" << perimeter() << std::endl;
    }
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : Shape("Circle"), r(r) {}
    double area() const override { return M_PI * r * r; }
    double perimeter() const override { return 2 * M_PI * r; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : Shape("Rectangle"), w(w), h(h) {}
    double area() const override { return w * h; }
    double perimeter() const override { return 2 * (w + h); }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : Shape("Triangle"), a(a), b(b), c(c) {}
    double area() const override {
        double s = (a + b + c) / 2.0;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override { return a + b + c; }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Triangle>(3.0, 4.0, 5.0));
    shapes.push_back(std::make_unique<Circle>(3.0));
    
    // Display all
    for (const auto& s : shapes) s->display();
    
    // Total area
    double total = std::accumulate(shapes.begin(), shapes.end(), 0.0,
        [](double sum, const std::unique_ptr<Shape>& s) { return sum + s->area(); });
    std::cout << "\nTotal area: " << total << std::endl;
    
    // Sort by area (descending)
    std::sort(shapes.begin(), shapes.end(),
        [](const auto& a, const auto& b) { return a->area() > b->area(); });
    
    std::cout << "\nSorted by area (desc) ---" << std::endl;
    for (const auto& s : shapes) s->display();
    
    // Count shapes with area > 20
    int large = std::count_if(shapes.begin(), shapes.end(),
        [](const auto& s) { return s->area() > 20.0; });
    std::cout << "\nShapes with area >20: " << large << std::endl;
    
    return 0;
}
