#include <iostream>
#include "stats.h"

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    double mean, stddev;

    calculate_stats(arr, size, mean, stddev);
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "StdDev: " << stddev << std::endl;

    return 0;
}
