class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);

        slow = slow->next;

        while(slow != nullptr) {
            if(head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* next = nullptr;

        while(head != nullptr) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
