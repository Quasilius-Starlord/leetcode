#include <iostream>
#include <string>
#include <cstdlib>

class Solution{
private:
    int unit(char c, int ascii){
            // std::cout << (int) c << " " << ascii << "\n";
        if((int)c>ascii){
            return 1;
        }else if((int)c<ascii){
            return -1;
        }else{
            return 0;
        }
    }

    bool posetive(int x){
        std::string s=std::to_string(x);
        // std::cout << s << "\n";
        if(s.length()>10)
            return false;
        if(s.length()<10)
            return true;
        
        // std::cout << (int)s[0] << "\n";
        // return true;


        //2
        int response=this->unit(s[9],50);
        // std::cout << "respionse " << response << "\n";
        if(response==1){
            return false;
        }else if(response==-1){
            return true;
        }else{
            //1
            response=this->unit(s[8],49);
            if(response==1){
                return false;
            }else if(response==-1){
                return true;
            }else{
                //4
                response=this->unit(s[7],52);
                if(response==1){
                    return false;
                }else if(response==-1){
                    return true;
                }else{
                    //7
                    response=this->unit(s[6],55);
                    if(response==1){
                    return false;
                    }else if(response==-1){
                        return true;
                    }else{
                        //4
                        response=this->unit(s[5],52);
                        if(response==1){
                            return false;
                        }else if(response==-1){
                            return true;
                        }else{
                            //8
                            response=this->unit(s[4],56);
                            if(response==1){
                                return false;
                            }else if(response==-1){
                                return true;
                            }else{
                                //3
                                response=this->unit(s[3],51);
                                if(response==1){
                                    return false;
                                }else if(response==-1){
                                    return true;
                                }else{
                                    //6
                                    response=this->unit(s[2],54);
                                    if(response==1){
                                        return false;
                                    }else if(response==-1){
                                        return true;
                                    }else{
                                        //4
                                        response=this->unit(s[1],52);
                                        if(response==1){
                                            return false;
                                        }else if(response==-1){
                                            return true;
                                        }else{
                                            //7
                                            response=this->unit(s[0],55);
                                            if(response==1){
                                                return false;
                                            }else if(response==-1){
                                                return true;
                                            }else{
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    };

    bool negetive(int x){
        std::string s=std::to_string(x);
        s=s.substr(1,s.length()-1);
        // std::cout << s << " " << s.length() << "\n";

        if(s.length()>10)
            return false;
        if(s.length()<10)
            return true;
        //2
        int response=this->unit(s[9],50);
        // std::cout << "respionse " << response << "\n";
        if(response==1){
            return false;
        }else if(response==-1){
            return true;
        }else{
            //1
            response=this->unit(s[8],49);
            if(response==1){
                return false;
            }else if(response==-1){
                return true;
            }else{
                //4
                response=this->unit(s[7],52);
                if(response==1){
                    return false;
                }else if(response==-1){
                    return true;
                }else{
                    //7
                    response=this->unit(s[6],55);
                    if(response==1){
                    return false;
                    }else if(response==-1){
                        return true;
                    }else{
                        //4
                        response=this->unit(s[5],52);
                        if(response==1){
                            return false;
                        }else if(response==-1){
                            return true;
                        }else{
                            //8
                            response=this->unit(s[4],56);
                            if(response==1){
                                return false;
                            }else if(response==-1){
                                return true;
                            }else{
                                //3
                                response=this->unit(s[3],51);
                                if(response==1){
                                    return false;
                                }else if(response==-1){
                                    return true;
                                }else{
                                    //6
                                    response=this->unit(s[2],54);
                                    if(response==1){
                                        return false;
                                    }else if(response==-1){
                                        return true;
                                    }else{
                                        //4
                                        response=this->unit(s[1],52);
                                        if(response==1){
                                            return false;
                                        }else if(response==-1){
                                            return true;
                                        }else{
                                            //8
                                            response=this->unit(s[0],56);
                                            if(response==1){
                                                return false;
                                            }else if(response==-1){
                                                return true;
                                            }else{
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    };

    int turn(int x){
        int t=0;
        while (x!=0)
        {
            int con=x%10;
            t=t*10+con;
            x=(x-(x%10))/10;
        }
        return t;
    }
public:
    int reverse(int x){
        bool response=true;
        if(x==0)
            return 0;

        if(x>0)
            response=this->posetive(x);
        else
            response=this->negetive(x);
        if(response==false)
            return 0;
        else
            return this->turn(x);
    }
};

int main(){
    int number;
    std::cin >> number;
    Solution solution;

    std::cout << solution.reverse(number);
}