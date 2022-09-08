/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//     ListNode* reverse(ListNode *node){
//         ListNode *prev=NULL;
//         ListNode *curr=node;
//         while (curr!=NULL){
//             ListNode *next=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=next;
//         }
//         return prev;
        
//     }
//     ListNode* reverse2(ListNode *node){
//         if (node==NULL)
//             return NULL;
//         if (node->next==NULL)
//             return node;
//         ListNode *head=reverse(node->next);
//         ListNode *tail=curr->next;
//         tail->next=curr;
//         node->next=NULL;
//         return head;
//     }
    void insertATtail(ListNode* &head,int data){
        ListNode *temp=new ListNode(data);
        if (head==NULL){
            head=temp;
            return ;
        }
        ListNode *curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3;
        int carry=0;
        while (l1!=NULL || l2!=NULL || carry!=0){
            int val1=0;
            if (l1!=NULL){
                val1=l1->val;
            }
            
            int val2=0;
            if (l2!=NULL){
                val2=l2->val;
            }
            int sum=val1+val2+carry;
            int digit=sum%10;
            carry=sum/10;
            
            insertATtail(l3,digit);

            carry=sum/10;   
            if (l1!=NULL)
                 l1=l1->next;
            if (l2!=NULL)
                l2=l2->next;
        
           }
          return l3;
   
    }
};