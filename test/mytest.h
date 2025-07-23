#ifndef MYTEST_H
#define MYTEST_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <sstream>

using namespace std;

struct TestCase {
    string name;
    function<string()> func;
    string expected;
};

vector<TestCase> test_cases;
int test_total = 0;
int test_fail = 0;

void REGISTER_SAMPLE(function<void()> sample, string expected, string name) {
    test_cases.push_back({
        name,
        [=]() {
            // Redirect cout to capture output
            streambuf* old_buf = cout.rdbuf();
            ostringstream output;
            cout.rdbuf(output.rdbuf());

            sample();

            cout.rdbuf(old_buf);
            return output.str();
        },
        expected
    });
}

void TEST_RUNNER() {
    vector<pair<string, pair<string, string>>> failed_tests;

    for (const auto& test : test_cases) {
        test_total++;
        string got = test.func();
        while (!got.empty() && (got.back() == '\n' || got.back() == '\r')) got.pop_back();
        string exp = test.expected;

        if (got == exp) {
            cout << "[PASS] " << test.name << '\n';
        } else {
            test_fail++;
            failed_tests.push_back({test.name, {exp, got}});
            cout << "[FAIL] " << test.name << '\n';
        }
    }

    // In chi tiết những test bị fail sau khi đã chạy hết
    if (!failed_tests.empty()) {
        cout << "\n=== Failed Details ===\n";
        cout << string(40, '-') << '\n';
        for (const auto& fail : failed_tests) {
            cout << "Test: " << fail.first << "\n\n";
            cout << "Expected | Got:\n\n";
            cout << fail.second.first << '\n';
            cout << fail.second.second << "\n\n";
            cout << string(40, '-') << '\n';
        }
    }

    cout << "\nTotal: " << test_total
         << ", Passed: " << (test_total - test_fail)
         << ", Failed: " << test_fail << '\n';
}

#endif