/*
    take l1 node take l2 node
*/

/**
 * Definition for singly-linked list.
 */
#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* setter(){
    int length,x;
    std::cout << "enter the length of number ";
    std::cin >> length;
        std::cin >> x;
        ListNode* returnable=new ListNode(x);
        ListNode* container=returnable;
    for (int i = 0; i < length-1; i++){
        std::cin >> x;
        ListNode* y=new ListNode(x);
        container->next=y;
        container=y;
    }
    return returnable;
}

void printer(ListNode* y){
    if(y==NULL)
        return;
    do
    {
        std::cout << y->val << " ";
        y=y->next;
    } while (y!=NULL);
    std::cout << "\n";
}

class Solution{
private:
    int completion(ListNode* l0,int carry){
        l0->val=l0->val+carry;
        if(l0->val>9){
            l0->val=l0->val%10;
            return 1;
        }else
            return 0;
            
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        // printer(l1);printer(l2);
        ListNode* returnable=NULL;
        ListNode* tran=returnable;
        ListNode *x=NULL,*y=NULL;
        int carry=0;
        int add=0;
        // x=l1;y=l2;
        do
        {
            add=l1->val+l2->val+carry;
            l1=l1->next;l2=l2->next;
            if(add>9){
                carry=1;
                add=add%10;
            }
            else{
                carry=0;
            }

            if(tran){
                tran->next=new ListNode(add);
                tran=tran->next;
            }else{
                returnable=new ListNode(add);
                tran=returnable;
            }

            // std::cout << l1 << " " << l2;
        } while (l1!=NULL && l2!=NULL);
        
        ListNode* nonNeutral=NULL;

        // std::cout << "l1" << " and " << "l2";

        if(l1!=NULL)
            nonNeutral=l1;
        else if(l2!=NULL)
            nonNeutral=l2;
        else{
            if(carry==0)
                return returnable;
            else{
                tran->next=new ListNode(carry);
                return returnable;
            }
        }

        // std::cout << nonNeutral;

        if(carry==0)
            tran->next=nonNeutral;
        else{
            // nonNeutral->val=nonNeutral->val+carry;
            tran->next=nonNeutral;
            while(carry!=0){
                carry=this->completion(nonNeutral,carry);
                if(nonNeutral->next==NULL && carry==1){
                    nonNeutral->next=new ListNode(carry);
                    carry=0;
                }
                nonNeutral=nonNeutral->next;
            }
        }
        return returnable;
    }
};

int main(){
    std::cout << "First linked list\n";
    ListNode* first=setter();
    ListNode* second=setter();
    // printer(first);
    // printer(second);

    Solution solution;
    ListNode* sum=solution.addTwoNumbers(first,second);
    printer(sum);
}