#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

struct Student {
    std::string name;
    double gpa;
    std::string major;
};

int main() {
    std::vector<Student> students = {
        {"Ahmed", 3.8, "CS"},
        {"Sara", 3.9, "CS"},
        {"Omar", 2.5, "CE"},
        {"Lina", 3.2, "CS"},
        {"Khalid", 3.0, "CE"},
        {"Noor", 3.7, "CS"}
    };
    
    // Sort by GPA descending
    std::sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) { return a.gpa > b.gpa; });
    
    // Average GPA
    double avg = std::accumulate(students.begin(), students.end(), 0.0,
        [](double sum, const Student& s) { return sum + s.gpa; }) / students.size();
    
    // Count per major
    std::map<std::string, int> major_count;
    for (const auto& s : students) major_count[s.major]++;
    
    // Honor list (GPA > 3.5)
    std::cout << "--- Rankings ---" << std::endl;
    for (const auto& s : students)
        std::cout << s.name << " (" << s.major << "): " << s.gpa << std::endl;
    
    std::cout << "\nAverage GPA: " << avg << std::endl;
    
    std::cout << "\nPer Major ---" << std::endl;
    for (const auto& [major, count] : major_count)
        std::cout << major << ": " << count << " students" << std::endl;
    
    std::cout << "\nHonor List ---" << std::endl;
    std::for_each(students.begin(), students.end(), [](const Student& s) {
        if (s.gpa > 3.5) std::cout << s.name << " (" << s.gpa << ")" << std::endl;
    });
    
    return 0;
}
