#include<iostream>
using namespace std;
#include<bits/stdc++.h>

ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return nullptr;
    
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* temp;
    while(curr->next != nullptr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    curr->next = prev;
    
    return curr;
}