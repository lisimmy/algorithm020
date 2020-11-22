class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode * retHead = new ListNode();
        ListNode * temp = retHead;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        // 循环结束， l1和l2至少有一个遍历结束
        if(l1 != nullptr)
            temp->next = l1;
        if(l2 != nullptr)
            temp->next = l2;
        return retHead->next;
    }
};
