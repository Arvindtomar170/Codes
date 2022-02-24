//floyd's cycle finding algoritham for detection of loop
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
bool Iscircular(node *&head)
{
    node *temp = head;
    while (true)
    {
        if (temp->next == head)
        {
            return true;
        }
        if (temp->next == NULL)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}
void makecircular(node *&head)
{
    if (Iscircular(head))
    {
        cout << "The list is alrady circular" << endl;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
}
void insertAtHead(int data, node *&head)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void detectLoop(node *head)  //main function of this programm 
{
    if (head == NULL || head->next == NULL)
    {
        cout << "No loop found in the list not suficient element to form list : " << endl;
        return;
    }
    node *slow = head, *fast = head->next;
    while (slow != NULL && fast != NULL && slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow == fast)
    {
        cout << "The list contain a loop :" << endl;
        return;
    }
    else
    {
        cout << "The list does not contain a loop : " << endl;
    }
}
void print(node *head)
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
    insertAtHead(1, head);
    insertAtHead(2, head);
    insertAtHead(3, head);
    insertAtHead(4, head);
    insertAtHead(5, head);
    insertAtHead(6, head);
    insertAtHead(7, head);
    insertAtHead(8, head);
    insertAtHead(9, head);
    print(head);
    cout << endl;
    if (Iscircular(head))
        cout << "The list is circular \n";
    else
        cout << "The list is not circular \n";
    makecircular(head);
    if (Iscircular(head))
        cout << "The list is circular \n";
    detectLoop(head);

    return 0;
}