#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> resultMap;
        int requiredNumber = 0;

        for (int i {0}; i < nums.size(); ++i) {
            requiredNumber = target - nums[i];
            
            // Return the indexes if we have them
            if (resultMap.count(requiredNumber)) {
                return {resultMap[requiredNumber], i};
            }
            
            // Or just save the index and iterate again
            resultMap[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    vector<int> test1 {2,7,11,15};
    int target1 = 9;
    
    vector<int> test2 {3,2,4};
    int target2 = 6;

    vector<int> test3 {3,3};
    int target3 = 6;

    Solution sol;
    auto res = sol.twoSum(test1, target1);

    std::cout << "[ ";
    for (auto value : res)
    {
        std::cout << value << " ";
    }

    std::cout << "]" << std::endl;

    return 0;
}
