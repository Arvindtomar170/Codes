//get nth data and find the lengh kof the list
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
void InsertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
int lengthUsingRecursive(node *head)
{
    if (head == NULL)
        return 0;
    else
        return 1 + lengthUsingRecursive(head->next);
}

// iterative methord
void getNth(node *head, int index)
{
    while (head != NULL && index > 0)
    {
        head = head->next;
        index--;
    }
    if (index == 0)
    {
        cout << head->data << endl;
    }
    else
    {
        cout << "Not sufficient element in the list : " << endl;
    }
}
// recursive methord of finding nth index
int getNth1(node *head, int index)
{
    if (index == 0)
        return head->data;
    else if (head == NULL && index > 0)
        return -999;

    else
        return (getNth1(head->next, index - 1));
}
void PrintInRevese(node *head)
{
    if (head == NULL)
        return;
    else
    {
        PrintInRevese(head->next);
        cout << head->data << " ";
        return;
    }
}
void deleteList(node *&head)
{
    node *current=head,*next;
    while (current!=NULL)
    {
          next=current->next;
         free(current);
         current=next;
    }
     head=NULL;


}
int main()
{
    node *head = NULL;
    InsertAtHead(head, 1);
    InsertAtHead(head, 2);
    InsertAtHead(head, 3);
    InsertAtHead(head, 4);
    InsertAtHead(head, 5);
    cout << "The length of the list is : " << length(head) << endl;
    cout << "The length of the list is : " << lengthUsingRecursive(head) << endl;
    print(head);
    cout << endl;
    PrintInRevese(head);
    deleteList(head);
    print(head);
    return 0;
}