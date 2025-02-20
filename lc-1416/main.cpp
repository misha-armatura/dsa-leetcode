#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int MOD = 1000000007;
        const int n = s.length();
        
        vector<int> result(n + 1, 0);
        result[n] = 1;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') continue;
            
            uint64_t num = 0;
            for (int j = i; j < n; ++j) {
                num = num * 10 + (s[j] - '0');
                if (num > k) break;
                
                result[i] = (result[i] + result[j + 1]) % MOD;
            }
        }
        
        return result[0];
    }
};

int main()
{
    string testString1 {"1000"};
    int testNumber1 {10000};

    string testString2 {"1000"};
    int testNumber2 {10};

    string testString3 {"1317"};
    int testNumber3 {2000};

    Solution sol;
    auto res = sol.numberOfArrays(testString3, testNumber3);

    std::cout << "[";
    std::cout << " " << res << " ";
    std::cout << "]" << std::endl;

    return 0;
}
