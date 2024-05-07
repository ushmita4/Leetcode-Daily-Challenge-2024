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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* h1=curr->next;
            curr->next=prev;
            prev=curr;
            curr=h1;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr=head;
        ListNode* newhead=reverse(head);
        ListNode* newheadrev=newhead;
        int c=0;
        while(newheadrev!=NULL){
            int nodeval=newheadrev->val*2+c;
            newheadrev->val=nodeval%10;
            c=nodeval/10;
            if(!newheadrev->next && c>0){
                newheadrev->next=new ListNode(c);
                break;
            }
            newheadrev=newheadrev->next;
        }
        return reverse(newhead);
    }
};
