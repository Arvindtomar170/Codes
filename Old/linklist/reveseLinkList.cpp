#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x, node *p = NULL)
    {
        data = x;
        next = p;
    }
};
void reverseList(node* &head)
{
    node* current=head,*pre=NULL,*nex=NULL;
    while (current!=NULL)
    {
         nex=current->next;
         current->next=pre;
         pre=current;
         current=nex;
    }
    head=pre;
}
void appendNodeAtEnd(int d, node *&head)
{
    node *temp = new node(d);
    node *ptr = head;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    node *head = NULL;
    appendNodeAtEnd(41, head);
    appendNodeAtEnd(44, head);
    appendNodeAtEnd(46, head);
    appendNodeAtEnd(47, head);
    appendNodeAtEnd(48, head);
    appendNodeAtEnd(49, head);
    appendNodeAtEnd(423, head);
    appendNodeAtEnd(45, head);
    // reverseList(head);
    printList(head);
    return 0;
}