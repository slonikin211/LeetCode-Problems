#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> buffer_values;   // [to_find_value, current_value]
        std::map<int, int> indexes;         // [current_value, index]
        
        const size_t& size = nums.size();

        for (size_t i = 0u; i < size; ++i)
        {
            const auto& current = nums.at(i);
            if (buffer_values.count(current) == 0u)
            {
                buffer_values[target - current] = current;
                indexes[current] = i;
            }
            else
            {
                return {indexes.at(buffer_values.at(current)), static_cast<int>(i)};
            }
        }
        // Never reach
        return {0, 0};
    }
};


int main()
{   
    Solution sln;
    
    // TDD

    // Test 1 from Example 1:
    {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        vector<int> res = sln.twoSum(nums, target);
        assert(res == vector<int>({0, 1}));
    }

    // Test 2 from Example 2:
    {
        vector<int> nums = {3, 2, 4};
        int target = 6;
        vector<int> res = sln.twoSum(nums, target);
        assert(res == vector<int>({1, 2}));
    }

    // Test 3 from Example 3:
    {
        vector<int> nums = {3, 3};
        int target = 6;
        vector<int> res = sln.twoSum(nums, target);
        assert(res == vector<int>({0, 1}));
    }

    return 0;
}