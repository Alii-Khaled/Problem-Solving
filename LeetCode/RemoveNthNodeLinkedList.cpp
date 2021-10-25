#include<iostream>
using namespace std;
#include<bits/stdc++.h>

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;
    
    while(fastPtr->next != nullptr && n > 0){
        fastPtr = fastPtr->next;
        n--;
    }
    
    if(n > 0){
        head = head->next;
        return head;
    }
    
    while(fastPtr->next != nullptr){
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
    }
    
    ListNode* temp = slowPtr->next;
    
    slowPtr->next = slowPtr->next->next;
    return head;
}