#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>

class Solution{
private:
    std::unordered_map<char,int> filter;
    int space;
public:
    Solution(){
        this->space=0;
    };

    std::vector<std::string> split(std::string s){
        int first=0;
        std::vector<std::string> words;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]==' '){
                words.push_back(s.substr(first,i-first));
                first=i+1;
            }
        }
        words.push_back(s.substr(first));
        for (int i = 0; i < words.size(); i++)
        {
            std::cout << words[i] << " words\n";
        }
        return words;
    }

    int canBeTypedWords(std::string text, std::string brokenLetters) {
        std::vector<std::string> words=this->split(text);
        int wordCount=words.size();
        for (int i = 0; i < words.size(); i++)
        {
            std::unordered_map<char,int> fermi;
            // std::cout << "for word " << words[i] << "\n";
            for (int j = 0; j < words[i].size(); j++)
                fermi[words[i][j]]=j;
            for (int j = 0; j < brokenLetters.length(); j++)
            {
                if(fermi.find(brokenLetters[j])!=fermi.end()){
                    wordCount--;
                    break;
                    // std::cout << "for alphabet- " << fermi.find(brokenLetters[j])->second << "\n";
                }
            }
            
        }
        return wordCount;
    }

    
    int canBeTypedWordsTwo(std::string text, std::string brokenLetters) {
        this->space=text.length();
        int position=-1;
        for (int i = 0; i < text.length(); i++)
        {
            if(text[i]==' '){
                this->space=i;
                continue;
            }
            if(filter.find(text[i])==filter.end()){
                // std::cout << text[i] << " " << "not found\n";
                if(i<this->space)
                    filter[text[i]]=-1;
                else
                    filter[text[i]]=1;
            }else{
                // std::cout << text[i] << " " << "found\n";
                position=i<this->space ? -1 : 1;
                if(filter.find(text[i])->second!=position)
                    filter[text[i]]=0;
                else{
                    continue;
                }
            }
        }
        // std::unordered_map<std::string, int>:: iterator p;
        // for (auto p = filter.begin(); p != filter.end(); p++)
        //     std::cout << "(" << p->first << ", " << p->second << ")\n";
            // std::cout << "(" << filter.find('d')->first << ", " << filter.find('d')->second << ")\n";
        int visible=0;
        for (int i = 0; i < brokenLetters.length(); i++)
        {
            if(filter.find(brokenLetters[i])==filter.end())
                continue;
            else{
                position=filter.find(brokenLetters[i])->second;
                if(position==0)
                    return 0;
                if(visible==0);{
                    visible=position*-1;
                    continue;
                }
                if(position==visible)
                    continue;
                else
                    return 0;
            }
        }
        if(visible==0)
            return 2;
        else
            return 1;
    }
};

int main(){
    std::string s="hello world";std::string bl="ad";
    // std::getline(std::cin,s);
    // std::cin >> bl;
    // std::cout << s;
    Solution solution;
    std::cout << solution.canBeTypedWords(s,bl);
}