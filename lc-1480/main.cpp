#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        uint64_t increment {0};
        vector<int> resultArray;

        for (auto &value : nums) {
            increment += value;
            resultArray.push_back(increment);
        }

        return resultArray;
    }
};

int main()
{
    vector<int> test1 {1,2,3,4};
    vector<int> test2 {1,1,1,1};

    Solution sol;
    auto res = sol.runningSum(test1);

    std::cout << "[ ";
    for (auto value : res)
    {
        std::cout << value << " ";
    }

    std::cout << "]" << std::endl;

    return 0;
}
