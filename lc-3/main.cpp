#include <iostream>
#include <array>
#include <cstdint>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // For getting better runtime speed we use sliding window with hash table
    int lengthOfLongestSubstring(std::string s) {
        // Store the last seen index of each ASCII character (0 - 127)
        std::array<short, 128> arr {}; // We use array for better working with cache
        arr.fill(-1);

        uint16_t maxCount { 0 };

        for (uint16_t right = 0, left = 0, n = s.length(); right < n; ++right) {
            // If the character was seen within the current window, move 'left' forward
            if (arr[s[right]] >= left) {
                left = arr[s[right]] + 1;
            }
            
            // Update the last seen index of the character
            arr[s[right]] = right;

            // Update longest substring counter
            maxCount = std::max(maxCount, static_cast<uint16_t>(right - left + 1));
        }

        return maxCount;
    }
};

int main()
{
    // Test 1
    string first = "abcabcbb";

    // Test 2
    string second = "bbbbb";

    // Test 3
    string third = "pwwkew";

    Solution sol;
    auto res = sol.lengthOfLongestSubstring(third);

    std::cout << "[ " << res << " " << "]" << std::endl;

    return 0;
}
