#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <unordered_map>

using DataType = int;
DataType read_data(const std::string &filename) {
    auto puzzle_filename = "puzzle_inputs/" + filename;
    std::ifstream is{puzzle_filename, std::ios_base::binary};
    std::cout << puzzle_filename << std::endl;
    if (not is.is_open()) {
        std::cout << "Could not open " << puzzle_filename << std::endl;
        return {};
    }
    DataType data{};
    while (is) {
        // blah
    }

    return data;
}

int part1(const std::string &filename) {
    auto data = read_data(filename);
    auto answer = 0;
    return answer;
}

bool part1() {
    auto test_answer = part1("test/day.txt");
    auto expected_test_answer = 0;
    if (test_answer != expected_test_answer) {
        std::cout << "Expected: " << expected_test_answer << " and got " << test_answer << std::endl;
    }

    auto actual_answer = part1("actual/day.txt");
    std::cout << "Answer: " << actual_answer << std::endl;
    return test_answer == expected_test_answer;
}

int part2(const std::string &filename) {
    auto data = read_data(filename);
    auto answer = 0;
    return answer;
}

bool part2() {
    auto test_answer = part2("test/day.txt");
    auto expected_test_answer = 0;
    if (test_answer != expected_test_answer) {
        std::cout << "Expected: " << expected_test_answer << " and got " << test_answer << std::endl;
    }

    auto actual_answer = part2("actual/day.txt");
    std::cout << "Answer: " << actual_answer << std::endl;
    return test_answer == expected_test_answer;
}

int main() {
    auto result = part1();

    result &= part2();
    return result;
}

