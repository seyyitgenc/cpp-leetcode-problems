#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *tail = dummyHead;
        int carry = 0 ;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int digit1 = (l1 != nullptr) ?  l1->val :  0;
            int digit2 = (l2 != nullptr) ?  l2->val :  0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            ListNode * newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;            
            l2 = (l2 != nullptr) ? l2->next : nullptr;            
        }
        ListNode * result = dummyHead->next;
        delete dummyHead;
        return result;
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
    Solution sol;
    ListNode *l1 = new ListNode(9);
    l1 = addToLast(5,l1);
    printf("1. list\n");
    traverse(l1);
    ListNode* l2 = new ListNode(3);
    printf("\n2. list\n");
    traverse(l2);
    ListNode* answer = sol.addTwoNumbers(l1 , l2);
    printf("\nanswer: ");
    traverse(answer);
    return 0;

}