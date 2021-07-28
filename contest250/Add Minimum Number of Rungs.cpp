#include <iostream>
#include <vector>
#include<bits/stdc++.h>
// #include <fixed_point.h>

class Solution{
private:
    void print(std::vector<int>& vec){
        for (int i = 0; i < vec.size(); i++)
            std::cout << vec[i] << "\n";
    };
public:
    int addRungs(std::vector<int>& rungs, int dist) {
        int first=0;
        int second=0;
        int count=rungs.size();
        int point=0;
        std::vector<int> repair;
        for (int i = 0; i < count; i++)
        {
            first=second;
            second=rungs[i];
            if((second-first)>dist){
                //whatever
                std::cout << (float)(second-first)/(float)dist << "\n";
                int step=0;
                // if((float)(second-first)/(float)dist==(second-first)/dist)
                //     step=((second-first)/dist)-1; 
                // else
                //     step=(second-first)/dist;
                // if you ever need to find the difference between two points number of fulfilling steps use this
                step=(second-first-1)/dist;
                // int init=first;
                std::cout << "step " << second << " " << first << " " << std::setprecision(6) << (double)(second-first)/(double)dist << 1000000000.0/999999998.0 << "\n";
                // for (int j = 0; j < step; j++)
                {
                    // rungs.insert(rungs.begin()+i,init+dist);
                    // init+=dist;
                    // point++;
                    // i++;
                }
                point+=step;
                // count=count+step;
            }
        }
        this->print(rungs);
        return point;



        // offitiaal answer
        // int ret = 0;
        // rungs.insert(rungs.begin(),0);
		// for (int i = 1; i < rungs.size(); i++) {
		// 	if (rungs[i] - rungs[i-1] <= dist) {
		// 		continue;
		// 	}
		// 	else {
        //         std::cout << (rungs[i] - rungs[i-1] - 1) / dist << "\n";
		// 		ret += (rungs[i] - rungs[i-1] - 1) / dist;
		// 	}
		// }
		// return ret;
    };
};

int main(){
    std::vector<int> vec{3};
    Solution solution;
    long double first=22;
    long double second=7;
    // std::cout.setprecision(4);
    // std::cout  << first/second;
    std::cout << solution.addRungs(vec,2);
}