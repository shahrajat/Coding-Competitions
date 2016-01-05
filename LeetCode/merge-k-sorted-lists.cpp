/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <queue>
 #include <vector>
class Solution {
public:
    struct comp{
        bool operator ()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> q;
        ListNode dummy(0);
        ListNode *itr = &dummy;
        
        for(ListNode *list : lists)
            if(list)
                q.push(list);
        
        while(!q.empty())
        {
            ListNode *min = q.top();
            q.pop();
            itr->next = min;
            itr = itr->next;
            if(min->next)
                q.push(min->next);
        }
        return dummy.next;
        
    }
};
