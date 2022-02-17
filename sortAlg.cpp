//
// Created by mihsa on 17.02.2022.
//

#include "sortAlg.h"
#include <chrono>
#include <fstream>
#include <utility>

 bool sortAlg::checkSorted(std::vector<int> vector) {
    if (vector.empty()) {
        return true;
    }
    int prev = vector[0];
    for (int64_t i = 1; i < vector.size(); ++i) {
        if (vector[i] < prev) {
            return false;
        }
        prev = vector[i];
    }
    return true;
}



std::vector<int> sortAlg::bubbleSort(std::vector<int> vector) {
    bool stop = false;
    while (!stop) {
        stop = true;
        for (int i = 0; i < vector.size() - 1; ++i) {
            if (vector[i] > vector[i + 1]) {
                stop = false;
                std::swap(vector[i], vector[i + 1]);
            }
        }
    }
    return vector;
}

std::vector<int> sortAlg::simpleInsert(std::vector<int> vector) {
    for (int ii = 0; ii < vector.size(); ++ii) {
        for (int j = ii; j > 0; --j) {
            if (vector[j - 1] > vector[j]) {
                std::swap(vector[j - 1], vector[j]);
            } else {
                break;
            }
        }
    }
    return vector;
}

std::vector<int> sortAlg::selectionSort(std::vector<int> vector) {
    int64_t length = vector.size(), min, index_min;
    for (int ii = 0; ii < length; ++ii) {
        min = INT_MAX;
        index_min = -1;
        for (int j = ii; j < length; ++j) {
            if (vector[j] < min) {
                min = vector[j];
                index_min = j;
            }
        }
        if (ii != index_min && index_min != -1) {
            std::swap(vector[ii], vector[index_min]);
        }
    }
    return vector;
}

std::string recordSortTime(int i, std::vector<int> vector, std::vector<int> (*f)(std::vector<int>)) {
    std::vector<int> sorting_vector = std::vector<int>();
    for (int j = 0; j < i; ++j) {
        sorting_vector.push_back(vector[i]);
    }
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    f(sorting_vector);
    if (!(sortAlg::checkSorted(sorting_vector))) {
        return "SORTING ERROR!!!!\n";
    } else {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        return "Time difference = " +
               std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()) +
               "[ns]\n";
    }
}

std::string sortAlg::recordSelectionTime(int i, std::vector<int> vector) {
    return recordSortTime(i, std::move(vector), sortAlg::selectionSort);
}

std::string sortAlg::recordBubbleTime(int i, std::vector<int> vector) {
    return recordSortTime(i, std::move(vector), sortAlg::bubbleSort);
}

std::string sortAlg::recordSimpleInsertTime(int i, std::vector<int> vector) {
    return recordSortTime(i, std::move(vector), sortAlg::simpleInsert);
}

