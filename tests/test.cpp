// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>

#include <substring.hpp>

#include <fstream>
#include <functional>
#include <vector>
#include <string>

namespace {
struct TestCase {
  size_t found;
  std::string input;
  std::string find;
};

void LoadTests(const std::string& filename, std::vector<TestCase>* out) {
  std::ifstream fl(filename);
  if (!fl.is_open()) return;

  while (!fl.eof()) {
    TestCase test_case;

    fl >> test_case.found;
    fl >> test_case.input;
    fl >> test_case.find;

    out->push_back(std::move(test_case));
  }
}
}  // namespace

TEST(Substring, Strstr) {
  std::vector<TestCase> tests;
  LoadTests("../misc/tests.txt", &tests);
  for (const auto& test_case : tests) {
    EXPECT_EQ(test_case.found, strstr(test_case.input, test_case.find))
        << "find " << test_case.find << " in " << test_case.input;
  }
}

TEST(Substring, RK) {
  std::vector<TestCase> tests;
  LoadTests("../misc/tests.txt", &tests);
  for (const auto& test_case : tests) {
    EXPECT_EQ(test_case.found, rk_find(test_case.input, test_case.find))
        << "find " << test_case.find << " in " << test_case.input;
  }
}

TEST(Substring, KMP) {
  std::vector<TestCase> tests;
  LoadTests("../misc/tests.txt", &tests);
  for (const auto& test_case : tests) {
    EXPECT_EQ(test_case.found, kmp_find(test_case.input, test_case.find))
        << "find " << test_case.find << " in " << test_case.input;
  }
}
