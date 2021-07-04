#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void printer(int* y,int len){
    if(y==NULL)
        return;
    std::cout << "size " << len << "\n";
    for (int i = 0; i < len; i++)
    {
        std::cout << y[i] << " ";
    }
    
    std::cout << "\n";
}

class Solution{
private:
public:
    std::unordered_map<char,int>* filter=new std::unordered_map<char,int>;
    Solution(){
        // for (int i = 97; i <= 122; i++){
        //     this->filter[i]=-1;
        // }
        // if(filter.find('x')==filter.end()){
        //     std::cout << "not forunf\n";
        // }
        // std::cout << filter.end()->second;
        //abcabcbb
    }

    void reInit(char specefic,int index){
        this->filter->find(specefic)->second=index;

        // this->filter->insert({specefic, 1});
    }

    // int* LengthOfLongestSubstring(std::string s){
    //     int* arr=new int[s.length()];
    //     // std::cout << s.length() << " ";
    //     int i=1,j=0;
    //     arr[0]=0;
    //     std::cout << arr[0] << " ";
    //     while ( i < s.length() )
    //     {
    //         if(s[i]==s[j]){
    //             arr[i]=j+1;
    //             i++;
    //             j++;
    //         }else{
    //             if(j<1){
    //                 arr[i]=0;
    //                 i++;
    //             }else{
    //                 while (s[j]!=s[i] && !(j<1) )
    //                 {
    //                     j=arr[j-1];
    //                 }
    //                 if(s[j]==s[i]){
    //                     arr[i]=j+1;
    //                     i++;
    //                 }else if(s[j]!=s[i]){
    //                     arr[i]=0;
    //                     i++;
    //                 }
    //             }
    //         }
    //     std::cout << arr[i-1] << " x";

    //     }
    //     return arr;
    // }

    int lengthOfLongestSubstring(std::string s){
        int returnable=0;
        int base=0;
        // if(s=="")
        //     std::cout << "emmpty";
        for (int i = 0; i < s.length(); i++)
        {
            if (this->filter->find(s[i])==this->filter->end())
            {
                //not present in list
                // returnable++;
                // std::cout << i << " " << base << "\n";
                // this->filter[s[i]];
                this->filter->insert({s[i],i});
                // if(this->filter->find(s[i])->second)
            }else{
                // std::cout << "entered\n";
                if(this->filter->find(s[i])->second+1>base)
                    base=this->filter->find(s[i])->second+1;
                this->reInit(s[i],i);
            }
                if((i-base+1)>returnable)
                    returnable=i-base+1;
            
        }
        return returnable;
    }

};

int main(){
    std::string s;
    std::cin >> s;
    Solution solution;
    int y=solution.lengthOfLongestSubstring(s);
    // printer(y,s.length());
    std::cout << y << "\n";
    return 0;
}