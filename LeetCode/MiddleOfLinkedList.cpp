#include<iostream>
using namespace std;
#include<bits/stdc++.h>

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
        
        if(fast->next != NULL)
            fast = fast->next;
    }
    return slow;
}