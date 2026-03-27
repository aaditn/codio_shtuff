#include <iostream>
#include "bigint.h"

using namespace std;

// Write your implementation below
BigInt::BigInt(std::string s) {
  if (s.empty()) {
      nums.push_back(0);
      return;
    }

  for (int i = s.length() - 1; i >= 0; i--) {
    nums.push_back(s[i] - '0');
  }
}

std::string BigInt::to_string() const {
  if (nums.empty()) {
    return "0";
  } else {
    std::string res = "";
    for (int i = nums.size() - 1; i >= 0; i--) {
      res += nums[i] + '0';
    }
    return res;
  }
}

void BigInt::add(BigInt b) {
  int tracker_self = nums.size();
  int tracker_b = b.nums.size();

  int carry = 0;
  int index = 0;

  while (index < tracker_b || index < tracker_self || carry != 0)  {
    int sum = carry;

    if (index < tracker_b) {
      sum += b.nums[index];
    }

    if (index < tracker_self) {
      sum += nums[index];
    }
    
    carry = sum / 10;
    sum %= 10;
    if (index < tracker_self) {
      nums[index] = sum;
    } else {
      nums.push_back(sum);
    }
    index++;
  }
}