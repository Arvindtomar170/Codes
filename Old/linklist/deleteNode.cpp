//delete n nodes after m  nodes
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val = 0)
    {
        data = val;
        next = NULL;
    }
};
void AppendAtHead(node *&head, int val)
{
    node *temp = new node(val);
    temp->next = head;
    head = temp;
}
void deletenode(node *head, int m, int n)
{
    node *temp = head, *temp1 = head;
    while (temp != NULL)
    {
        for (int i = 1; i < m && temp != NULL; i++)
        {
            temp = temp->next;
        }
        temp1 = temp;
        if (temp == NULL)
            return;
        for (int i = 0; i <= n && temp != NULL; i++)
        {
            node *t = temp;
            temp = temp->next;
            delete (t);
        }
        temp1->next = temp;
        temp1 = temp;
    }
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;

    AppendAtHead(head, 1);
    AppendAtHead(head, 2);
    AppendAtHead(head, 4);
    AppendAtHead(head, 5);
    AppendAtHead(head, 6);
    AppendAtHead(head, 7);
    AppendAtHead(head, 8);
    print(head);
    deletenode(head, 3, 3);
    print(head);
    return 0;
}