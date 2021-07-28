#include <iostream>

class Solution{
private:
public:
    bool isPalindrome(long long int x) {
        long long int comp=x;
        if(x<0)
            return false;
        long long int pusher=0;
        while (x!=0)
        {
            long long int con=x%10;
            pusher=pusher*10+con;
            x=(x-con)/10;
        }
        if(comp==pusher)
            return true;
        else
            return false;
    }

};

long long int main(){
    long long int num;
    std::cin >> num;

    Solution solution;
    std::cout << solution.isPalindrome(num);
    return 0;
    // std::cout << solution->
}