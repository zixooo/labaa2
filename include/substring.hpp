// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_SUBSTRING_HPP_
#define INCLUDE_SUBSTRING_HPP_
#include <iostream>
#include <string>
#include <cstring>
#include <vector>


size_t str_find(const std::string& a, const std::string& b);
size_t rk_find(const std::string& str, const std::string& substr);
size_t kmp_find(const std::string& str, const std::string& substr);

#endif // INCLUDE_SUBSTRING_HPP_
