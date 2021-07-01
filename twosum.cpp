#include <iostream>
#include <vector>

class Solution{
private:
    // std::vector<int> nums
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target){
        std::vector<int> output;
        int a,b;
        for (int i = 0; i < nums.size(); i++)
        {
            a=nums[i];
            for(int  j=0;j<nums.size(); j++){
                if(i==j)
                    break;
                if((target-a)==nums[j]){
                    output.push_back(i);
                    output.push_back(j);
                    return output;
                }
            }

        }
        return output;
    }
};

int main(){
    std::vector<int> num;
    int target,len;
    std::cin >> len;
    for (int i = 0; i < len; i++)
    {
        int container;
        std::cin >> container;
        num.push_back(container);
    }
    std::cin >> target;
    Solution solution;
    std::vector<int> output=solution.twoSum(num,target);
    for(int i = 0; i < output.size(); i++)
    {
        // int container;
        std::cout << output[i] << " ";
        // num.push_back(container);
    }
}