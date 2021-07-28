#include <iostream>
#include <string>

class Solution{
private:
    int chartoint(char c){
        switch (c)
        {
        case '0':
            return 0;
        break;
        case '1':
            return 1;
        break;
        case '2':
            return 2;
        break;
        case '3':
            return 3;
        break;
        case '4':
            return 4;
        break;
        case '5':
            return 5;
        break;
        case '6':
            return 6;
        break;
        case '7':
            return 7;
        break;
        case '8':
            return 8;
        break;
        case '9':
            return 9;
        break;
        default:
            return 0;
        }
    };

    int strtonum(std::string s,bool sign){
        int num=0;
        for (int i = 0; i < s.length(); i++)
        {
            if(sign)
                num=num*10+this->chartoint(s[i]);
            else
                num=num*10-this->chartoint(s[i]);
        }
        return num;
    }
public:
    int myAtoi(std::string s){
        bool flag=true,sign=true;int integer=0;
        int container=0;
        int left=-1;
        int right=-1;
        int first=true;
        for (int i = 0; i < s.length(); i++)
        {
            if(first){
                if(s[i]==' '){
                    continue;
                }
            }
            if(flag==true){
                if(s[i]=='-'){
                    sign=false;flag=false;
                    first=!first;
                    continue;
                }
                else if(s[i]=='+'){
                    sign=true;flag=false;
                    first=!first;
                    continue;
                }
            }
            // if((right-left+1)>10)
            //     return 0;
            
            //     std::cout << (int)s[i] << "\n";
            if((int)s[i]>=48 && (int)s[i]<=57){
                flag=false;
                if(left==-1 && right==-1){
                    left=i;
                    // std::cout << "hrtr\n";
                    right=i;
                    first=!first;
                }else{
                    if((right-left+1)>=9){
                    int content=this->strtonum(s.substr(left,right-left+1),true);
                        if(content>214748364){
                            if(sign){
                                // if(this->chartoint(s[i])>7)
                                    return INT32_MAX;
                            }else{
                                // if(this->chartoint(s[i])>8)
                                    return INT32_MIN;
                            }
                        }
                        else if(content==214748364){
                            if(sign){
                                if(this->chartoint(s[i])>7)
                                    return INT32_MAX;
                            }else{
                                if(this->chartoint(s[i])>8)
                                    return INT32_MIN;
                            }
                        }
                    }
                    right++;
                }
            }else{
                // if(s[i]!='-' || )
                    break;
            }
        }
        if(left==-1 && right==-1){
            return integer;
        }else{
            // integer=
            return this->strtonum(s.substr(left,right-left+1),sign);
        }
    };
};

int main(){
    std::string s;
    std::cin >> s;
    Solution solution;
    // if(INT32_MAX+5>INT32_MAX)
    //     std::cout << "overflow\n";
    // int i=INT32_MAX+5;   +0 123
    std::cout << solution.myAtoi(s);
}