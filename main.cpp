#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <fstream>
#include "sortAlg.h"




int main() {
    std::vector<int> vector_0_5 = std::vector<int>();
    std::vector<int> vector_0_4000 = std::vector<int>();
    std::vector<int> vector_4100_1_reverse = std::vector<int>();
    std::vector<int> vector_0_4000_almost = std::vector<int>();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::ofstream file_stream;

    std::uniform_int_distribution<int> uni(0, 5);
    for (int j = 0; j <= 4100; ++j) {
        vector_0_5.push_back(uni(rng));
    }
    uni = std::uniform_int_distribution<int>(0, 4000);
    for (int j = 0; j <= 4100; ++j) {
        vector_0_4000.push_back(uni(rng));
    }
    uni = std::uniform_int_distribution<int>(1, 4100);
    for (int j = 0; j <= 4100; ++j) {
        vector_4100_1_reverse.push_back(uni(rng));
    }
    std::sort(vector_4100_1_reverse.begin(), vector_4100_1_reverse.end());
    std::reverse(vector_4100_1_reverse.begin(), vector_4100_1_reverse.end());
    uni = std::uniform_int_distribution<int>(0, 4000);
    for (int j = 0; j <= 4100; ++j) {
        vector_0_4000_almost.push_back(uni(rng));
    }
    std::sort(vector_0_4000_almost.begin(), vector_0_4000_almost.end());
    for (int64_t i = 0; i < vector_0_4000_almost.size() - 1; i += vector_0_4000_almost.size() / 50) {
        std::swap(vector_0_4000_almost[i], vector_0_4000_almost[vector_0_4000_almost.size() - i - 1]);
    }

    //
    //
    //INSERT SORT-------------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-5
    file_stream.open("dat\\insert\\50-300 0-5.txt");
    std::cout << "50-300 [0,5]\n";
    for (int i = 50; i <= 300; i += 10) {
        file_stream << sortAlg::recordSelectionTime(i, vector_0_5);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000
    file_stream.open("dat\\insert\\50-300 0-4000.txt");
    std::cout << "\n\n50-300 [0,4000]\n\n";
    for (int i = 50; i <= 300; i += 10) {
        file_stream << sortAlg::recordSelectionTime(i, vector_0_4000);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000 almost sorted
    file_stream.open("dat\\insert\\50-300 0-4000 almost sorted.txt");
    std::cout << "\n\n50-300 [0,4000] almost sorted\n\n";
    for (int i = 50; i <= 300; i += 10) {
        file_stream << sortAlg::recordSelectionTime(i, vector_0_4000_almost);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000 reverse
    file_stream.open("dat\\insert\\50-300 0-4000 reverse.txt");
    std::cout << "\n\n50-300 [0,4000] reverse\n\n";
    for (int i = 50; i <= 300; i += 10) {
        file_stream << sortAlg::recordSelectionTime(i, vector_4100_1_reverse);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-5
    file_stream.open("dat\\insert\\100-4100 0-5.txt");
    std::cout << "\n\n100-4100 [0,5]\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        file_stream << sortAlg::recordSelectionTime(i, vector_0_5);
    }
    file_stream.close();


    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000
    file_stream.open("dat\\insert\\100-4100 0-4000.txt");
    std::cout << "\n\n100-4100 [0,4000]\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        file_stream << sortAlg::recordSelectionTime(i, vector_0_4000);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000 almost sorted
    file_stream.open("dat\\insert\\100-4100 0-4000 almost sorted.txt");
    std::cout << "\n\n100-4100 [0,4000] almost sorted\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        file_stream << sortAlg::recordSelectionTime(i, vector_0_4000_almost);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000 reverse
    file_stream.open("dat\\insert\\100-4100 0-4000 reverse.txt");
    std::cout << "\n\n100-4100 [0,4000] reverse\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        file_stream << sortAlg::recordSelectionTime(i, vector_4100_1_reverse);
    }
    file_stream.close();

    //
    //
    //BUBBLE SORT-------------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-5
    file_stream.open("dat\\bubble\\50-300 0-5.txt");
    std::cout << "50-300 [0,5]\n";
    for (int i = 50; i <= 300; i += 10) {
        file_stream << sortAlg::recordBubbleTime(i, vector_0_5);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000
    file_stream.open("dat\\bubble\\50-300 0-4000.txt");
    std::cout << "\n\n50-300 [0,4000]\n\n";
    for (int i = 50; i <= 300; i += 10) {
        file_stream << sortAlg::recordBubbleTime(i, vector_0_4000);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000 almost sorted
    file_stream.open("dat\\bubble\\50-300 0-4000 almost sorted.txt");
    std::cout << "\n\n50-300 [0,4000] almost sorted\n\n";
    for (int i = 50; i <= 300; i += 10) {
        file_stream << sortAlg::recordBubbleTime(i, vector_0_4000_almost);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000 reverse
    file_stream.open("dat\\bubble\\50-300 0-4000 reverse.txt");
    std::cout << "\n\n50-300 [0,4000] reverse\n\n";
    for (int i = 50; i <= 300; i += 10) {
        file_stream << sortAlg::recordBubbleTime(i, vector_4100_1_reverse);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-5
    file_stream.open("dat\\bubble\\100-4100 0-5.txt");
    std::cout << "\n\n100-4100 [0,5]\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        file_stream << sortAlg::recordBubbleTime(i, vector_0_5);
    }
    file_stream.close();


    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000
    file_stream.open("dat\\bubble\\100-4100 0-4000.txt");
    std::cout << "\n\n100-4100 [0,4000]\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        file_stream << sortAlg::recordBubbleTime(i, vector_0_4000);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000 almost sorted
    file_stream.open("dat\\bubble\\100-4100 0-4000 almost sorted.txt");
    std::cout << "\n\n100-4100 [0,4000] almost sorted\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        file_stream << sortAlg::recordBubbleTime(i, vector_0_4000_almost);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000 reverse
    file_stream.open("dat\\bubble\\100-4100 0-4000 reverse.txt");
    std::cout << "\n\n100-4100 [0,4000] reverse\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        file_stream << sortAlg::recordBubbleTime(i, vector_4100_1_reverse);
    }
    file_stream.close();

    //
    //
    //SIMPLE INSERT SORT-------------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-5
    file_stream.open("dat\\sinsert\\50-300 0-5.txt");
    std::cout << "50-300 [0,5]\n";
    for (int i = 50; i <= 300; i += 10) {
        sortAlg::recordSimpleInsertTime(i, vector_0_5);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000
    file_stream.open("dat\\sinsert\\50-300 0-4000.txt");
    std::cout << "\n\n50-300 [0,4000]\n\n";
    for (int i = 50; i <= 300; i += 10) {
        sortAlg::recordSimpleInsertTime(i, vector_0_4000);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000 almost sorted
    file_stream.open("dat\\sinsert\\50-300 0-4000 almost sorted.txt");
    std::cout << "\n\n50-300 [0,4000] almost sorted\n\n";
    for (int i = 50; i <= 300; i += 10) {
        sortAlg::recordSimpleInsertTime(i, vector_0_4000_almost);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000 reverse
    file_stream.open("dat\\sinsert\\50-300 0-4000 reverse.txt");
    std::cout << "\n\n50-300 [0,4000] reverse\n\n";
    for (int i = 50; i <= 300; i += 10) {
        sortAlg::recordSimpleInsertTime(i, vector_4100_1_reverse);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-5
    file_stream.open("dat\\sinsert\\100-4100 0-5.txt");
    std::cout << "\n\n100-4100 [0,5]\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        sortAlg::recordSimpleInsertTime(i, vector_0_5);
    }
    file_stream.close();


    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000
    file_stream.open("dat\\sinsert\\100-4100 0-4000.txt");
    std::cout << "\n\n100-4100 [0,4000]\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        sortAlg::recordSimpleInsertTime(i, vector_0_4000);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000 almost sorted
    file_stream.open("dat\\sinsert\\100-4100 0-4000 almost sorted.txt");
    std::cout << "\n\n100-4100 [0,4000] almost sorted\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        sortAlg::recordSimpleInsertTime(i, vector_0_4000_almost);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000 reverse
    file_stream.open("dat\\sinsert\\100-4100 0-4000 reverse.txt");
    std::cout << "\n\n100-4100 [0,4000] reverse\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        sortAlg::recordSimpleInsertTime(i, vector_4100_1_reverse);
    }
    file_stream.close();


    //
    //
    //BINARY INSERT SORT-------------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-5
    file_stream.open("dat\\binsert\\50-300 0-5.txt");
    std::cout << "50-300 [0,5]\n";
    for (int i = 50; i <= 300; i += 10) {
        sortAlg::recordBinaryInsertTime(i, vector_0_5);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000
    file_stream.open("dat\\binsert\\50-300 0-4000.txt");
    std::cout << "\n\n50-300 [0,4000]\n\n";
    for (int i = 50; i <= 300; i += 10) {
        sortAlg::recordBinaryInsertTime(i, vector_0_4000);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000 almost sorted
    file_stream.open("dat\\binsert\\50-300 0-4000 almost sorted.txt");
    std::cout << "\n\n50-300 [0,4000] almost sorted\n\n";
    for (int i = 50; i <= 300; i += 10) {
        sortAlg::recordBinaryInsertTime(i, vector_0_4000_almost);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //50-300 0-4000 reverse
    file_stream.open("dat\\binsert\\50-300 0-4000 reverse.txt");
    std::cout << "\n\n50-300 [0,4000] reverse\n\n";
    for (int i = 50; i <= 300; i += 10) {
        sortAlg::recordBinaryInsertTime(i, vector_4100_1_reverse);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-5
    file_stream.open("dat\\binsert\\100-4100 0-5.txt");
    std::cout << "\n\n100-4100 [0,5]\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        sortAlg::recordBinaryInsertTime(i, vector_0_5);
    }
    file_stream.close();


    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000
    file_stream.open("dat\\binsert\\100-4100 0-4000.txt");
    std::cout << "\n\n100-4100 [0,4000]\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        sortAlg::recordBinaryInsertTime(i, vector_0_4000);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000 almost sorted
    file_stream.open("dat\\binsert\\100-4100 0-4000 almost sorted.txt");
    std::cout << "\n\n100-4100 [0,4000] almost sorted\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        sortAlg::recordBinaryInsertTime(i, vector_0_4000_almost);
    }
    file_stream.close();

    //------------------------------------------------------------------------------------------------------------------
    //100-4100 0-4000 reverse
    file_stream.open("dat\\binsert\\100-4100 0-4000 reverse.txt");
    std::cout << "\n\n100-4100 [0,4000] reverse\n\n";
    for (int i = 100; i <= 4100; i += 100) {
        sortAlg::recordBinaryInsertTime(i, vector_4100_1_reverse);
    }
    file_stream.close();

    return 0;
}