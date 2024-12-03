#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>


using DataType = std::vector<std::vector<int>>;

DataType read_data(const std::string &filename) {
    auto puzzle_filename = "puzzle_inputs/" + filename;
    std::ifstream is{puzzle_filename, std::ios_base::binary};
    std::cout << puzzle_filename << std::endl;

    if (not is.is_open()) {
        std::cout << "Could not open " << puzzle_filename << std::endl;
        return {};
    }
    DataType data{};
    std::string line;
    while (std::getline(is, line)) {
        std::istringstream ss(line);
        data.emplace_back();
        std::copy(std::istream_iterator<int>(ss), std::istream_iterator<int>(), std::back_inserter(data.back()));
    }

    return data;
}


bool test_report(std::vector<int> report, int remove) {
    if (remove >= 0) {
        report.erase(report.begin() + remove);
    }

    auto max_delta = 3;

    bool safe = true;
    auto last_direction = true;

    for (auto i = 1; i < report.size() and safe; i++) {
        auto delta = std::abs(report[i] - report[i - 1]);
        safe &= 0 < delta and delta <= max_delta;

        auto direction = (report[i] - report[i - 1]) > 0;
        if (i > 1 and last_direction != direction) {
            safe = false;
        }
        last_direction = direction;
    }

    return safe;
}

int part1(const std::string &filename) {
    auto data = read_data(filename);

    auto max_delta = 3;

    auto safe_count = 0;
    for (auto &&report: data) {
        safe_count += test_report(report, -1);
    }

    return safe_count;
}

bool part1() {
    auto test_answer = part1("test/day2.txt");
    auto expected_test_answer = 2;
    if (test_answer != expected_test_answer) {
        std::cout << "Expected: " << expected_test_answer << " and got " << test_answer << std::endl;
    }

    auto actual_answer = part1("actual/day2.txt");
    std::cout << "Answer: " << actual_answer << std::endl;
    return test_answer == expected_test_answer;
}

int part2(const std::string &filename) {
    auto data = read_data(filename);

    auto safe_count = 0;
    for (auto &&report: data) {
        auto safe = test_report(report, -1);

        for (auto i = 0; i < report.size() and not safe; i++) {
            safe |= test_report(report, i);
        }

        safe_count += safe;
    }

    return safe_count;
}

bool part2() {
    auto test_answer = part2("test/day2.txt");
    auto expected_test_answer = 4;
    if (test_answer != expected_test_answer) {
        std::cout << "Expected: " << expected_test_answer << " and got " << test_answer << std::endl;
    }

    auto actual_answer = part2("actual/day2.txt");
    std::cout << "Answer: " << actual_answer << std::endl;
    return test_answer == expected_test_answer;
}

int main() {
    auto result = part1();
    result &= part2();
    return not result;
}

