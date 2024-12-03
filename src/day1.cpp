#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <unordered_map>

std::pair<std::vector<int>, std::vector<int>> read_data(const std::string &filename) {
    auto puzzle_filename = "puzzle_inputs/" + filename;
    std::ifstream is{puzzle_filename, std::ios_base::binary};
    std::cout << puzzle_filename << std::endl;
    if (not is.is_open()) {
        std::cout << "Could not open " << puzzle_filename << std::endl;
        return {};
    }
    std::pair<std::vector<int>, std::vector<int>> data{};
    while (is) {
        int l, r;
        is >> l >> r;
        if (not is) { break; }
        data.first.push_back(l);
        data.second.push_back(r);
    }

    return data;
}

int part1(const std::string &filename) {
    auto data = read_data(filename);
    // build heaps of <number, index>
    std::priority_queue<int, std::vector<int>, std::greater<>> leftq, rightq;
    for (auto i = 0; i < data.first.size(); i++) {
        auto &left = data.first[i];
        auto &right = data.second[i];
        leftq.push(left);
        rightq.push(right);
    }

    auto distance = 0;
    while (not leftq.empty()) {
        distance += std::abs(leftq.top() - rightq.top());
        leftq.pop();
        rightq.pop();
    }

    return distance;
}

bool part1() {
    auto test_answer = part1("test/day1.txt");
    auto expected_test_answer = 11;
    if (test_answer != expected_test_answer) {
        std::cout << "Expected: " << expected_test_answer << " and got " << test_answer << std::endl;
    }

    auto actual_answer = part1("actual/day1.txt");
    std::cout << "Answer: " << actual_answer << std::endl;
    return test_answer == expected_test_answer;
}

int part2(const std::string &filename) {
    auto data = read_data(filename);
    std::unordered_map<int, int> count;
    for (auto &&r: data.second) {
        count[r]++;
    }

    auto score = 0;
    for (auto &&l: data.first) {
        score += l * count[l];
    }

    return score;
}

bool part2() {
    auto test_answer = part2("test/day1.txt");
    auto expected_test_answer = 31;
    if (test_answer != expected_test_answer) {
        std::cout << "Expected: " << expected_test_answer << " and got " << test_answer << std::endl;
    }

    auto actual_answer = part2("actual/day1.txt");
    std::cout << "Answer: " << actual_answer << std::endl;
    return test_answer == expected_test_answer;
}

int main() {
    auto result = part1();

    result &= part2();
    return result;
}

