#pragma once

#include "headers.hpp"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target);
    std::string longestCommonPrefix(std::vector<std::string> &strs);
    bool isValid(const std::string &s);
    int strStr(const std::string &haystack,
               const std::string &needle);
    int removeElement(std::vector<int> &nums, int val);
    std::vector<std::vector<int>> generate(int numRows);
    int lengthOfLastWord(const std::string &s);
    std::vector<int> plusOne(std::vector<int> &digits);
    int mySqrt(int x);
    int countOdds(int low, int high);
    double average(std::vector<int> &salary);
    int search(std::vector<int> &nums, int target);
    int hammingWeight(uint32_t n);
    int subtractProductAndSum(int n);
    int fib(int n);
    int tribonacci(int n);
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    std::vector<int> sortedSquares(std::vector<int>& nums);
    void rotate(std::vector<int>& nums, int k);
    int searchInsert(std::vector<int>& nums, int target);
    int firstBadVersion(int n);
    int largestPerimeter(std::vector<int>& nums);
    int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points);
    int arraySign(std::vector<int>& nums);
    void moveZeroes(std::vector<int>& nums);
    std::vector<int> twoSumSet(std::vector<int>& numbers, int target);
    std::string reverseWords(std::string s);
    void reverseString(std::vector<char>& s);
    bool canMakeArithmeticProgression(std::vector<int>& arr);
    bool isHappy(int n);
    bool checkInclusion(std::string s1, std::string s2);
};