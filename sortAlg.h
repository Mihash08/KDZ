//
// Created by mihsa on 17.02.2022.
//
#include <iostream>
#include <vector>
#include <fstream>

#ifndef KDZTEST_SORTALGO_H
#define KDZTEST_SORTALGO_H


class sortAlg {
public:

    static std::vector<int> selectionSort(std::vector<int> vector);

    static std::vector<int> bubbleSort(std::vector<int> vector);

    static std::vector<int> simpleInsert(std::vector<int> vector);

    static std::vector<int> binaryInsert(std::vector<int> vector);

    static bool checkSorted(std::vector<int> vector);

    static std::string recordSelectionTime(int i, std::vector<int> vector);

    static std::string recordBubbleTime(int i, std::vector<int> vector);

    static std::string recordSimpleInsertTime (int i, std::vector<int> vector);

    static std::string recordBinaryInsertTime (int i, std::vector<int> vector);
};


#endif //KDZTEST_SORTALGO_H
