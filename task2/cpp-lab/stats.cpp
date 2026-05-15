#include "stats.h"
#include <cmath>

void calculate_stats(const int* arr, int size, double& mean, double& stddev) {
    double sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    mean = sum / size;

    double variance = 0;
    for (int i = 0; i < size; i++) {
        variance += (arr[i] - mean) * (arr[i] - mean);
    }
    stddev = std::sqrt(variance / size);
}
