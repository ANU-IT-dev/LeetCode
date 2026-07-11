/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergetwosortedlists(ListNode *L1,ListNode *L2)
    {
        if(L2== NULL) return L1;
        if(L1== NULL) return L2;
        if(L1->val <= L2->val)
        {
            L1->next= mergetwosortedlists(L1->next,L2);
            return L1;

        }
        if(L2->val < L1->val)
        {
            L2->next =mergetwosortedlists(L2->next,L1);
            return L2;
        }
        return NULL;

    }
    ListNode *partitionandmerge(int s, int e, vector<ListNode*> &lists)
    {
        if(s>e) return NULL;
        if(s==e) return lists[s];
        int mid = s+(e-s)/2;

        ListNode *L1 =partitionandmerge(s,mid,lists);
        ListNode *L2 =partitionandmerge(mid+1,e,lists);

        return mergetwosortedlists(L1,L2);

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
      int k= lists.size();
      if(k==0) return NULL;
       return partitionandmerge(0,k-1,lists);
    }
};