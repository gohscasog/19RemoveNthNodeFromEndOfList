#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* p = head;
    struct ListNode* prev = p;

    int sz = 0;
    while(p != NULL)
    {
        if(sz > n)
        {
            prev = prev->next;
        }

        sz++;
        p = p->next;
    }

    if(sz == n)
    {
        return prev->next;
    }

    prev->next = prev->next->next;
    
    return head;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};

    struct ListNode n4 = {nums[4], NULL};
    struct ListNode n3 = {nums[3], &n4};
    struct ListNode n2 = {nums[2], &n3};
    struct ListNode n1 = {nums[1], &n2};
    struct ListNode n0 = {nums[0], &n1};
    
    struct ListNode* p = &n0;
    while(p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    p = removeNthFromEnd(&n0, 1);
    while(p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}