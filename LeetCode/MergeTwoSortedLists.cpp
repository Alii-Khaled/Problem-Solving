#include<iostream>
using namespace std;
#include<bits/stdc++.h>

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    ListNode* result;
    if(l1->val > l2->val){
        result = l2;
        l2 = l2->next;
    }
    else{
        result = l1;
        l1 = l1->next;
    }
    ListNode* resItr = result;
    
    while(l1 && l2){
        if(l1->val > l2->val){
            resItr->next = l2;
            l2 = l2->next;
        }
        else{
            resItr->next = l1;
            l1 = l1->next;
        }
        resItr = resItr->next;
    }
    if(l1){
        resItr->next = l1;
    }
    else{
        resItr->next = l2;
    }
    return result;
}