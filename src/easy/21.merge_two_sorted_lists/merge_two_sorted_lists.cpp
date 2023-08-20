#include <iostream>

// problem link : https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // early rejection
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;

        ListNode* iterl1 = list1;
        ListNode* iterl2 = list2;

        ListNode* result = new ListNode(0);
        // there must be a simpler way, just work on it 
        while (iterl1 != nullptr || iterl2 != nullptr)
        {
            ListNode* newNode = new ListNode();
            if (iterl1 != nullptr && iterl2 != nullptr)
            {
                if (iterl1->val <= iterl2->val){
                    newNode->val = iterl1->val;
                    iterl1 = iterl1->next;
                }
                else if (iterl1->val > iterl2->val){
                    newNode->val = iterl2->val;
                    iterl2 = iterl2->next;
                }
            }
            else if (iterl1 != nullptr && iterl2 == nullptr){
                newNode->val = iterl1->val;
                iterl1 = iterl1->next;
            }
            else if (iterl1 == nullptr && iterl2 != nullptr){
                newNode->val = iterl2->val;            
                iterl2 = iterl2->next;
            }

            ListNode* iter = result;
            while (iter->next != nullptr)
                iter = iter->next;
            iter->next = newNode;
        }
        //! there will be memory leak
        return result->next; 
    }
};

ListNode * addToLast(int x , ListNode *node){
    ListNode * iter = node;
    while(iter->next != nullptr)
        iter = iter->next;
    ListNode *newNode = new ListNode(x);
    iter->next = newNode; 
    return node;
}

ListNode * addToFront(int x,ListNode* node){
    ListNode *newNode = new ListNode(x);
    newNode->next = node; 
    return newNode;
}

void traverse(ListNode* node){
    ListNode* iter = node;
    while (iter != nullptr)
    {
        printf("%d",iter->val);
        iter = iter->next;
    }
}

int main(){

    // Input: a: 5->10->15, b: 2->3->20->30
    // Output: 2->3->5->10->15->20->30
    Solution sol;
    ListNode *l1 = new ListNode(1);
    l1 = addToLast(2,l1);
    l1 = addToLast(4,l1);
    printf("1. list\n");
    traverse(l1);
    ListNode* l2 = new ListNode(1);
    l2 = addToLast(3,l2);
    printf("\n2. list\n");
    traverse(l2);
    ListNode* answer = sol.mergeTwoLists(l1 , l2);
    printf("\nanswer: ");
    traverse(answer);
    return 0;

}