#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
//     }
// };


class HelpListNodes
{
    ListNode* head_;
public:
    HelpListNodes(const initializer_list<int>& init)
    {
        head_ = new ListNode(*init.begin());

        if (init.size() > 1u)
        {
            ListNode* current = head_;
            for (auto it = init.begin() + 1u; it != init.end(); ++it)
            {
                ListNode* next_node = new ListNode(*it);
                current->next = next_node;
                current = next_node;
            }
            current->next = nullptr;
        }
    }
    ~HelpListNodes()
    {
        if (head_->next == nullptr)
        {
            delete head_;
        }
        else
        {
            ListNode* next_node = head_->next;
            while (head_->next != nullptr)
            {
                delete head_;
                head_ = next_node;
                next_node = head_->next;
            }
            delete head_;
        }
    }

    ListNode* GetHead()
    {
        return head_;
    }
};

int main()
{   
    // Solution sln;
    
    // TDD

    // Test 0 Test help class HelpListNodes
    {
        HelpListNodes l = {1, 2, 3};
        assert(l.GetHead()->val == 1);
        assert(l.GetHead()->next->val == 2);
        assert(l.GetHead()->next->next->val == 3);
        assert(l.GetHead()->next->next->next == nullptr);
    }

    // Test 1 from Example 1
    // {
    //     ListNode l1(2);
    //     l1.next = new ListNode(4);
    //     l1.next->next = new ListNode(3);
    // }

    return 0;
}