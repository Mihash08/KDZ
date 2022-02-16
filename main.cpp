#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <fstream>

std::vector<int> vector = std::vector<int>();
namespace Main {
    bool checkSorted() {
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

    std::vector<int> bubbleSort() {
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

    std::vector<int> simpleInsert() {
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

    std::vector<int> selectionSort() {
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

    int main() {
        crash();
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
            vector.push_back(uni(rng));
        }
        selectionSort();
        vector_4100_1_reverse = vector;
        std::reverse(vector_4100_1_reverse.begin(), vector_4100_1_reverse.end());
        vector.clear();
        uni = std::uniform_int_distribution<int>(0, 4000);
        for (int j = 0; j <= 4100; ++j) {
            vector.push_back(uni(rng));
        }
        selectionSort();
        vector_0_4000_almost = vector;
        for (int64_t i = 0; i < vector_0_4000_almost.size() - 1; i += vector_0_4000_almost.size() / 50) {
            std::swap(vector_0_4000_almost[i], vector_0_4000_almost[vector_0_4000_almost.size() - i - 1]);
        }
        vector.clear();

        //
        //
        //INSERT SORT-------------------------------------------------------------------------------------------------------

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-5
        file_stream.open("dat\\insert\\50-300 0-5.txt");
        std::cout << "50-300 [0,5]\n";
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_5[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            selectionSort();
            if (!(checkSorted())) {
                file_stream << "SORTING ERROR!!!!\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-4000
        file_stream.open("dat\\insert\\50-300 0-4000.txt");
        std::cout << "\n\n50-300 [0,4000]\n\n";
        uni = std::uniform_int_distribution<int>(0, 4000);
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            selectionSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-4000 almost sorted
        file_stream.open("dat\\insert\\50-300 0-4000 almost sorted.txt");
        std::cout << "\n\n50-300 [0,4000] almost sorted\n\n";
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000_almost[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            selectionSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-4000 reverse
        file_stream.open("dat\\insert\\50-300 0-4000 reverse.txt");
        std::cout << "\n\n50-300 [0,4000] reverse\n\n";
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_4100_1_reverse[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            selectionSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-5
        uni = std::uniform_int_distribution<int>(0, 5);
        file_stream.open("dat\\insert\\100-4100 0-5.txt");
        std::cout << "\n\n100-4100 [0,5]\n\n";
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_5[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            selectionSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();


        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-4000
        file_stream.open("dat\\insert\\100-4100 0-4000.txt");
        std::cout << "\n\n100-4100 [0,4000]\n\n";
        uni = std::uniform_int_distribution<int>(0, 4000);
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            selectionSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-4000 almost sorted
        file_stream.open("dat\\insert\\100-4100 0-4000 almost sorted.txt");
        std::cout << "\n\n100-4100 [0,4000] almost sorted\n\n";
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000_almost[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            selectionSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-4000 reverse
        file_stream.open("dat\\insert\\100-4100 0-4000 reverse.txt");
        std::cout << "\n\n100-4100 [0,4000] reverse\n\n";
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_4100_1_reverse[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            selectionSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
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
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_5[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            bubbleSort();
            if (!(checkSorted())) {
                file_stream << "SORTING ERROR!!!!\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-4000
        file_stream.open("dat\\bubble\\50-300 0-4000.txt");
        std::cout << "\n\n50-300 [0,4000]\n\n";
        uni = std::uniform_int_distribution<int>(0, 4000);
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            bubbleSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-4000 almost sorted
        file_stream.open("dat\\bubble\\50-300 0-4000 almost sorted.txt");
        std::cout << "\n\n50-300 [0,4000] almost sorted\n\n";
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000_almost[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            bubbleSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-4000 reverse
        file_stream.open("dat\\bubble\\50-300 0-4000 reverse.txt");
        std::cout << "\n\n50-300 [0,4000] reverse\n\n";
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_4100_1_reverse[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            bubbleSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-5
        uni = std::uniform_int_distribution<int>(0, 5);
        file_stream.open("dat\\bubble\\100-4100 0-5.txt");
        std::cout << "\n\n100-4100 [0,5]\n\n";
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_5[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            bubbleSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();


        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-4000
        file_stream.open("dat\\bubble\\100-4100 0-4000.txt");
        std::cout << "\n\n100-4100 [0,4000]\n\n";
        uni = std::uniform_int_distribution<int>(0, 4000);
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            bubbleSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-4000 almost sorted
        file_stream.open("dat\\bubble\\100-4100 0-4000 almost sorted.txt");
        std::cout << "\n\n100-4100 [0,4000] almost sorted\n\n";
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000_almost[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            bubbleSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-4000 reverse
        file_stream.open("dat\\bubble\\100-4100 0-4000 reverse.txt");
        std::cout << "\n\n100-4100 [0,4000] reverse\n\n";
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_4100_1_reverse[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            bubbleSort();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
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
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_5[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            simpleInsert();
            if (!(checkSorted())) {
                file_stream << "SORTING ERROR!!!!\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-4000
        file_stream.open("dat\\sinsert\\50-300 0-4000.txt");
        std::cout << "\n\n50-300 [0,4000]\n\n";
        uni = std::uniform_int_distribution<int>(0, 4000);
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            simpleInsert();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-4000 almost sorted
        file_stream.open("dat\\sinsert\\50-300 0-4000 almost sorted.txt");
        std::cout << "\n\n50-300 [0,4000] almost sorted\n\n";
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000_almost[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            simpleInsert();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //50-300 0-4000 reverse
        file_stream.open("dat\\sinsert\\50-300 0-4000 reverse.txt");
        std::cout << "\n\n50-300 [0,4000] reverse\n\n";
        for (int i = 50; i <= 300; i += 10) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_4100_1_reverse[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            simpleInsert();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-5
        uni = std::uniform_int_distribution<int>(0, 5);
        file_stream.open("dat\\sinsert\\100-4100 0-5.txt");
        std::cout << "\n\n100-4100 [0,5]\n\n";
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_5[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            simpleInsert();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();


        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-4000
        file_stream.open("dat\\sinsert\\100-4100 0-4000.txt");
        std::cout << "\n\n100-4100 [0,4000]\n\n";
        uni = std::uniform_int_distribution<int>(0, 4000);
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            simpleInsert();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-4000 almost sorted
        file_stream.open("dat\\sinsert\\100-4100 0-4000 almost sorted.txt");
        std::cout << "\n\n100-4100 [0,4000] almost sorted\n\n";
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_0_4000_almost[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            simpleInsert();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();

        //------------------------------------------------------------------------------------------------------------------
        //100-4100 0-4000 reverse
        file_stream.open("dat\\sinsert\\100-4100 0-4000 reverse.txt");
        std::cout << "\n\n100-4100 [0,4000] reverse\n\n";
        for (int i = 100; i <= 4100; i += 100) {
            vector.clear();
            for (int j = 0; j < i; ++j) {
                vector.push_back(vector_4100_1_reverse[i]);
            }
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            simpleInsert();
            if (!(checkSorted())) {
                file_stream << "\n\nSORTING ERROR!!!!\n\n";
            } else {
                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                file_stream << "Time difference = "
                            << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
                            << "[ns]\n";
            }
        }
        file_stream.close();
        return 0;
    }
}