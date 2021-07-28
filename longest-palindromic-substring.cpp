#include <iostream>
#include <string>

class Solution{
private:
public:
//aacabdkacaa
    std::string longestPalindrome(std::string s){
        std::string returnable;
        int longest=0;
        int left=0,right=0;
        for (int i = 0; i < s.length(); i++)
        {
            left=i;
            right=i;
            while (left>=0 && right<s.length())
            {
                if(s[left]==s[right]){
                    if(longest<(right-left+1)){
                        longest=right-left+1;
                        returnable=s.substr(left,longest);
                        // std::co
                        std::cout << s[i] <<  " " << returnable << "\n";
                    }
                }else{
                    std::cout << s[i] <<  " " << "returnable" << "\n";
                    break;
                }
                left--;right++;
            }
        }
        left=0;right=1;
        for (int i = 0; i < s.length()-1; i++)
        {
            left=i;
            right=i+1;
            while (left>=0 && right<s.length())
            {
                if(s[left]==s[right]){
                    if(longest<(right-left+1)){
                        longest=right-left+1;
                        returnable=s.substr(left,longest);
                    }
                }else{
                    break;
                }
                left--;right++;
            }
        }
        // std::cout << longest;
        return returnable;
    }
};

int main(){
    std::string s;
    std::cin >> s;
    Solution solution;
    std::cout << solution.longestPalindrome(s);
}