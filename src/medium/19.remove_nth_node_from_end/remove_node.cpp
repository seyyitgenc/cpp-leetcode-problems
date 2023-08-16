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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* countIter = head;
        int listCount = 0;
        while (countIter != nullptr){
            countIter = countIter->next;
            listCount++;
        }

        if (listCount == n)
        {
            ListNode* node =  head;
            head = node->next;
            delete node;
            return head;
        }

        ListNode* tempHead = head;
        for (int i = 1; i < listCount - n; i++)
            tempHead = tempHead->next;
        ListNode* node = tempHead ->next;
        tempHead->next = tempHead->next->next;
        delete node;
        return head;
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
    ListNode *l1 = new ListNode(1);
    l1 = addToLast(2,l1);
    // l1 = addToLast(3,l1);
    // l1 = addToLast(4,l1);
    // l1 = addToLast(5,l1);
    printf("1. list\n");
    traverse(l1);
    ListNode* answer = sol.removeNthFromEnd(l1 , 1);
    printf("\nanswer: ");
    traverse(answer);
    return 0;

}