#include <vector>
using namespace std;

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
        ListNode* l3 = new ListNode();
        ListNode*cur = l3;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum = sum+l1->val;
                l1=l1->next;
            }
            if(l2){
                sum = sum+l2->val;
                l2=l2->next;
            }
            sum = sum+carry;
            carry = sum/10;
            ListNode * temp = new ListNode(sum%10);
            cur->next = temp;
            cur = cur->next;
        }
        return l3->next;
    }
};