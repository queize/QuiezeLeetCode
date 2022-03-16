#include "solution.hpp"

//-------------twoSum--------------------
std::vector<int> Solution::twoSum(std::vector<int> &nums, int target)
{
    int it_sum1, it_sum2;
    std::map<int, int> nums_map;
    for (const auto &x : nums)
    {
        nums_map[x] += 1;
    }
    int sum1 = 0, sum2 = 0;
    for (const auto &x : nums_map)
    {
        if (nums_map.count(target - x.first * x.second) &&
            target != x.first * x.second)
        {
            sum1 = target - x.first * x.second;
            sum2 = x.first * x.second;
            it_sum1 = std::find(nums.begin(), nums.end(), sum1) - nums.begin();
            it_sum2 = std::find(nums.begin(), nums.end(), sum2) - nums.begin();
        }
        else if (nums_map.count(target - x.first * x.second) &&
                 target == x.first * x.second)
        {
            sum1 = target - x.first * x.second;
            sum2 = x.first * x.second;
            it_sum1 = std::find(nums.begin(), nums.end(), sum1) - nums.begin();
            it_sum2 = std::find(nums.begin() + it_sum1 + 1, nums.end(), sum2) -
                      nums.begin();
        }
        else if (target == x.first * x.second)
        {
            sum1 = sum2 = x.first;
            it_sum1 = std::find(nums.begin(), nums.end(), sum1) - nums.begin();
            it_sum2 = std::find(nums.begin() + it_sum1 + 1, nums.end(), sum2) -
                      nums.begin();
        }
    }
    return std::vector<int>{std::min(it_sum1, it_sum2),
                            std::max(it_sum1, it_sum2)};
}
//-------------longestCommonPrefix--------------------
std::string min(const std::string &str1, const std::string &str2)
{
    return (str1.size() < str2.size()) ? str1 : str2;
}

std::string Solution::longestCommonPrefix(std::vector<std::string> &strs)
{
    std::string common;
    std::string min_common = strs[0];
    for (const auto &str : strs)
    {
        min_common = min(str, min_common);
    }
    for (size_t j = 0; j < min_common.size(); ++j)
    {
        std::set<char> set_char;
        for (size_t i = 0; i < strs.size(); ++i)
        {
            set_char.insert(strs[i][j]);
        }
        if (set_char.size() == 1)
        {
            common += *set_char.begin();
        }
        else
        {
            break;
        }
    }
    return common;
}
//-------------isValid--------------------

bool isOpen(char c) { return c == '(' || c == '{' || c == '['; }
bool isPair(char top, char c)
{
    return top == '(' && c == ')' || top == '[' && c == ']' ||
           top == '{' && c == '}';
}

bool Solution::isValid(const std::string &s)
{
    std::stack<char> st;
    for (const auto &ch : s)
    {
        if (isOpen(ch))
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && isPair(st.top(), ch))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}
//--------------strStr-------------
int Solution::strStr(const std::string &haystack, const std::string &needle)
{
    std::string local;
    if (haystack.size() < needle.size())
    {
        return -1;
    }
    for (size_t i = 0; i < haystack.size() - needle.size(); ++i)
    {
        local = std::string(haystack.begin() + i,
                            haystack.begin() + needle.size() + i);
        if (local == needle)
        {
            return std::find(haystack.begin(), haystack.end(), needle[0]) -
                   haystack.begin();
        }
    }
    return (haystack.empty() && needle.empty()) ? 0 : -1;
}
//-----------------------lengthOfLastWord----------------------//
int Solution::lengthOfLastWord(const std::string &s)
{
    int counter = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == ' ' && counter > 0)
        {
            return counter;
        }
        if (s[i] != ' ')
        {
            ++counter;
        }
    }
    return counter;
}
//-------------------------plusOne-------------------------//
std::vector<int> Solution::plusOne(std::vector<int> &digits)
{
    int mod_part = 0;
    int digit_part = 0;
    bool first = true;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it)
    {
        int new_mod_part = 0;
        int new_digit_part = 0;
        if (first)
        {
            ++*it;
            first = false;
        }
        new_digit_part = (*it + digit_part) / 10;
        new_mod_part = (*it + digit_part) % 10;
        digit_part = new_digit_part;
        *it = new_mod_part;
    }
    if (digit_part)
    {
        std::reverse(digits.begin(), digits.end());
        digits.push_back(digit_part);
        std::reverse(digits.begin(), digits.end());
    }
    return digits;
}
//--------------------mySqrt-----------------
int Solution::mySqrt(int x)
{
    double eps = 1e-2;
    double a = 0;
    double b = x;
    double middle = (a + b) / 2;
    while (std::abs(middle * middle - x) > eps)
    {
        (middle * middle > x ? b : a) = middle;
        middle = (a + b) / 2;
    }
    return round(middle) * round(middle) == x ? round(middle) : middle;
}
//---------------countOdds-------------------
int Solution::countOdds(int low, int high)
{
    int counter = (high - low + 1) / 2;
    if (high % 2 && low % 2)
    {
        ++counter;
    }
    return counter;
}
//---------------------average---------------------
double Solution::average(std::vector<int> &salary)
{
    auto it_max = std::max_element(salary.begin(), salary.end());
    auto it_min = std::min_element(salary.begin(), salary.end());

    size_t n = salary.size();
    int &min = *it_min;
    int &max = *it_max;

    double S = 0;
    for (const auto &x : salary)
    {
        S += x;
    }
    S /= n;

    double S1 = (1.0 * n / (n - 2)) * (S - 1.0 * (max + min) / n);
    return S1;
}
//----------------------search-----------------------
int Solution::search(std::vector<int> &nums, int target)
{
    int lhs = 0, rhs = nums.size() - 1, ans = 0;
    while (lhs <= rhs)
    {
        int mid = lhs + (rhs - lhs) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            lhs = ans = mid + 1;
        }
        else
        {
            rhs = mid - 1;
        }
    }
    return -1;
}
//----------------------hammingWeight-----------------
int Solution::hammingWeight(uint32_t n)
{
    uint8_t counter = 0;
    for (size_t i = 0; i < 32; ++i)
    {
        counter += (n & (1 << i)) ? 1 : 0;
    }
    return counter;
}
//-------------------------subtractProductAndSum-------------
int Solution::subtractProductAndSum(int n)
{
    int sum = 0, prod = 1;
    for (; n; n /= 10)
    {
        int digit = n % 10;
        sum += digit;
        prod *= digit;
    }
    return prod - sum;
}
//------------------------fib-----------------------
int Solution::fib(int n)
{
    std::vector<int> cache = {1, 1};
    if (n == 1 || n == 2)
    {
        return cache[0];
    }
    if (n == 0)
    {
        return 0;
    }
    for (int i = 3; i <= n; ++i)
    {
        cache.push_back(cache[i - 2] + cache[i - 3]);
    }
    return cache.back();
}
//-----------------------tribonacci---------------------
int Solution::tribonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    std::vector<int> cache = {0, 1, 1};
    int result = 0;
    for (int i = 3; i <= n; ++i)
    {
        result = cache[0] + cache[1] + cache[2];
        std::swap(cache[0], cache[1]);
        std::swap(cache[1], cache[2]);
        std::swap(cache[2], result);
    }
    return cache.back();
}
//------------------addTwoNumbers----------------------
//------------------sortedSquares----------------------
std::vector<int> Solution::sortedSquares(std::vector<int> &nums)
{
    std::vector<int> copy_nums = nums;
    for (auto &x : copy_nums)
    {
        x = std::pow(x, 2);
    }
    std::sort(copy_nums.begin(), copy_nums.end());
    return copy_nums;
}
//-----------------rotate------------------
void Solution::rotate(std::vector<int> &nums, int k)
{
    std::vector<int> copy_nums = nums;
    size_t n = nums.size();
    for (size_t i = 0; i < n; ++i)
    {
        nums[(i + k) % n] = copy_nums[i];
    }
}
//----------------searchInsert------------------------
int Solution::searchInsert(std::vector<int> &nums, int target)
{
    int lhs = 0;
    int rhs = nums.size() - 1;
    int ans = 0;

    while (lhs <= rhs)
    {
        int mid = (lhs + rhs) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            lhs = ans = mid + 1;
        }
        else
        {
            rhs = mid - 1;
        }
    }
    return ans;
}
//------------------firstBadVersion----------------
bool isBadVersion(int version)
{
    return 0;
}
int Solution::firstBadVersion(int n)
{
    return 0;
}
//-----------------largestPerimeter-----------------
int Solution::largestPerimeter(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    for (int i = nums.size() - 3; i >= 0; --i)
    {
        if (nums[i] + nums[i + 1] > nums[i + 2])
        {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }
    return 0;
}
//----------------nearestValidPoint-------------------
int Solution::nearestValidPoint(int x, int y, std::vector<std::vector<int>> &points)
{
    auto dist = [](int x1, int y1, int x2, int y2)
    {
        return std::abs(x1 - x2) + std::abs(y1 - y2);
    };
    return 0;
}
//---------------arraySign--------------------------
int signFunc(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return (x > 0) ? 1 : -1;
}

int Solution::arraySign(std::vector<int> &nums)
{
    int result = 1;
    for (const auto &x : nums)
    {
        result *= signFunc(x);
    }
    return result;
}
//------------------moveZeroes---------------------
void Solution::moveZeroes(std::vector<int> &nums)
{
    for (int j = 0, i = 0; i < nums.size(); i++)
    {
        if (nums[i])
        {
            std::swap(nums[j++], nums[i]);
        }
    }
}
//---------------twoSum-------------------------------
std::vector<int> Solution::twoSumSet(std::vector<int> &numbers, int target)
{
    int index1 = 0, index2 = 0;
    auto it_begin = numbers.begin();
    auto it_rbegin = numbers.rbegin();
    while (*it_begin != *it_rbegin)
    {
        if (target - *it_begin - *it_rbegin > 0)
        {
            index1 = it_begin - numbers.begin() + 1;
            index2 = numbers.size() - (it_rbegin - numbers.rbegin() + 1);
            break;
        }
        else if (target - *it_begin - *it_rbegin > 0)
        {
            ++it_begin;
        }
        else
        {
            ++it_rbegin;
        }
    }
    return std::vector<int>{index1, index2};
}
//----------------reverseWords
std::string Solution::reverseWords(std::string s)
{
    auto it_space_prev = s.begin(), it_space_current = s.begin();
    do
    {
        it_space_prev = it_space_current;
        it_space_current = std::find(it_space_prev, s.end(), ' ');
        std::reverse(it_space_prev, it_space_current);
    } while (it_space_current++ != s.end());
    return s;
}
//---------------reverseString------------------------
void Solution::reverseString(std::vector<char> &s)
{
    std::reverse(s.begin(), s.end());
}
//---------------canMakeArithmeticProgression----------
bool Solution::canMakeArithmeticProgression(std::vector<int> &arr)
{
    std::sort(arr.begin(), arr.end());
    int check = arr[1] - arr[0];
    for (size_t i = 2; i < arr.size(); ++i)
    {
        if (arr[i] - arr[i - 1] != check)
        {
            return false;
        }
    }
    return true;
}
//-----------------isHappy-------------------------------
std::vector<long long> deriveNumbers(int n)
{
    std::vector<long long> result;
    result.reserve(static_cast<long long>(std::log10(n)) + 1);
    while (n)
    {
        result.push_back(n % 10);
        n /= 10;
    }
    return result;
}
bool Solution::isHappy(int n)
{
    std::unordered_set<long long> sums;
    std::vector<long long> result;
    long long sum = n;
    while (!sums.count(sum) && sum * sum >= 10)
    {
        sums.insert(sum);
        result = deriveNumbers(sum);
        std::transform(result.begin(), result.end(), result.begin(),
                       [](const long long &x)
                       {
                           return x * x;
                       });
        sum = std::accumulate(result.begin(), result.end(), 0);
    }
    result = deriveNumbers(sum);
    std::transform(result.begin(), result.end(), result.begin(),
                   [](const long long &x)
                   {
                       return x * x;
                   });
    sum = std::accumulate(result.begin(), result.end(), 0);
    return (sum == 1) ? true : false;
}
//-------------------checkInclusion----------------
bool Solution::checkInclusion(std::string s1, std::string s2)
{
    std::map<char, int> s1_map;
    for (const auto &x : s1)
    {
        s1_map[x] += 1;
    }
    for (auto it_s2 = s2.begin(), it_s2_end = s2.begin() + s1.size() + 1;
         it_s2_end != s2.end();
         ++it_s2, ++it_s2_end)
    {
        std::map<char, int> s2_map;
        for (auto it = it_s2; it != it_s2 + s1.size() + 1; ++it)
        {
            s2_map[*it] += 1;
        }
        if (s1_map == s2_map)
        {
            return true;
        }
    }
    return false;
}