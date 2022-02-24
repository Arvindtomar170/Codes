#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void PrintList(node *head)
{
    cout << "Your list is as follow \n";
    while (head != 0)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void ReveseList(node *&head)
{
    node *pre = NULL, *current = NULL, *next = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head = pre;
}
void AddOne(node *&head)
{
    ReveseList(head);
    int carry = 1;
    node *temp = head,*temp2;
    while (temp!= NULL)
    {
        int x = (temp->data + carry) ;
        carry = x / 10;
        temp->data=x%10;
        temp2=temp;
        temp=temp->next;
    }
    if (carry==1)
    {
      node *n=new node(1);
      temp2->next=n;

    }
    ReveseList(head);
}
int AddwithCarry(node *&head)
{
    if(head==NULL)
    {
        return 1;
    }
    int res=head->data+AddwithCarry(head->next);
    head->data=res%10;
    return res/10;
}
void addRecursivly(node *&head)
{
    int carry=AddwithCarry(head);
    if(carry>0)
    {
        insertAthead(head,carry);
    }
}
int main()
{
    node *head = NULL;
    insertAthead(head, 9);
    insertAthead(head, 9);
    insertAthead(head, 9);
    insertAthead(head, 9);
    PrintList(head);
    addRecursivly(head);
    AddOne(head);
    PrintList(head);
    return 0;
}