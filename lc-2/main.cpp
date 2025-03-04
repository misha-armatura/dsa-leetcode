#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
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
        // Reduce allocation for better runtime time
        ListNode localHead{};
        ListNode* currentNode = &localHead;
        
        int ov = 0; // Overflow
        int tempSum = 0;

        while (l1 || l2 || ov) {
            // Avoid working with temp values
            tempSum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + ov;
            ov = tempSum / 10;

            currentNode->next = new ListNode{tempSum % 10};
            currentNode = currentNode->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return localHead.next;
    }
};

ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (auto i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    // Test 1
    ListNode* list11 = createList({2,4,3});
    ListNode* list12 = createList({5,6,4});

    // Test 2
    ListNode* list21 = createList({0});
    ListNode* list22 = createList({0});
    
    // Test 3
    ListNode* list31 = createList({9,9,9,9,9,9,9});
    ListNode* list32 = createList({9,9,9,9});

    Solution sol;
    auto res = sol.addTwoNumbers(list31, list32);

    std::cout << "[ " << res << " " << "]" << std::endl;

    deleteList(res);

    deleteList(list11);
    deleteList(list12);

    deleteList(list21);
    deleteList(list22);

    deleteList(list31);
    deleteList(list32);

    return 0;
}
