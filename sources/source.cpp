// Copyright 2020 Your Name <your_email>

#include <substring.hpp>

size_t str_find(const std::string& a, const std::string& b) {
  size_t n = a.size();
  size_t m = b.size();
  if (m > n) {
    return -1;
  } else {
    for (size_t i = 0; i < n - m + 1; i++) {
      for (size_t j = 0; j < m; j++) {
        if (a[i + j] == b[j]) {
          if (m - 1 == j) return i;
          continue;
        } else {
          break;
        }
      }
    }
    return -1;
  }
}

// hash hash oni kuryat hash
size_t rk_find(const std::string& a, const std::string& b) {
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;
  int n = a.size();
  int m = b.size();
  int q = m + n;
  int d = 256;
  for (i = 0; i < m - 1; i++) h = (h * d) % q;

  for (i = 0; i < m; i++) {
    p = (d * p + b[i]) % q;
    t = (d * t + a[i]) % q;
  }

  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (a[i + j] != b[j]) break;
      }
      if (i == 0) {
        return -1;
      } else {
        if (j == m) return i;
      }
    }
    if (i < n - m) {
      t = (d * (t - a[i] * h) + a[i + m]) % q;
      if (t < 0) t = (t + q);
    }
  }
  return -1;
}
std::vector<int> lps_func(const std::string& s);
size_t kmp_find(const std::string& a, const std::string& b) {
  size_t i;
  std::vector<int> pi = lps_func(b + '#' + a);
  int t_len = b.length();
  for (i = 0; i < a.size(); i++) {
    if (pi[t_len + 1 + i] == t_len) {
      return i - t_len + 1;
    }
  }
  return -1;
}

std::vector<int> lps_func(const std::string& s) {
  size_t i;
  std::vector<int> pi(s.length(), 0);
  for (i = 1; i < s.length(); i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      pi[i] = j + 1;
    } else {
      pi[i] = j;
    }
  }
  return pi;
}
