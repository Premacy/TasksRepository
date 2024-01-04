#include <iostream>

struct ListNode{
    int val;
    ListNode *next;

    ListNode(): val(0), next(nullptr) {};
    ListNode( int val_ ): val( val_), next(nullptr) {};
    ListNode( int val_ , ListNode *next_): val( val_), next(next_) {};
};

ListNode *RevertList( ListNode *head ){
    ListNode *curr = head;
    ListNode *newHead;
    ListNode *tmp;

    newHead = new ListNode( head->val );

    while( curr->next != nullptr ){
        curr = curr->next;
        
        tmp = new ListNode( curr->val );
        tmp->next = newHead;
        newHead = tmp;
    }

    return newHead;
}

void addElement( ListNode *head, int val ){
    ListNode *curr;
    curr = head;

    while( curr->next != nullptr ){
        curr = curr->next;
    }
    curr->next = new ListNode( val );
}

void printList( ListNode *head ){
    ListNode *curr;
    curr = head;

    while( curr != nullptr ){
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
}

int main(){

    ListNode *head = new ListNode(0);

    for( int i = 1; i < 10; i++ ){
        addElement( head, i );
    }

    auto revertHead = RevertList( head );
    printList( revertHead );

    return 0;
}
