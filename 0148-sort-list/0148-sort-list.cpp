class Solution {
public:

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (left != nullptr && right != nullptr) {

            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            }
            else {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        if (left != nullptr)
            curr->next = left;

        if (right != nullptr)
            curr->next = right;

        return dummy.next;
    }


    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split
        prev->next = nullptr;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge
        return merge(left, right);
    }
};