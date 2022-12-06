#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void multiply(Node* tail, int n) {
    Node* temp = tail, * prevNode = tail;
    int carry = 0;
    while (temp != NULL) {
        int data = temp->data * n + carry;
        temp->data = data % 10;
        carry =data/ 10;
        prevNode = temp;
        temp = temp->next;
    }
    while (carry!=0)
    {
        prevNode->next = new Node(carry % 10);
        carry /= 10;
        prevNode = prevNode->next;
    }

}

void print(Node* tail) {
    if (tail == NULL)return;
    print(tail->next);
    cout << tail->data;
}

int main()
{
    int n;
    cin >> n;
    Node tail(1);
    for (int i = 2;i <= n;i++)
        multiply(&tail, i);
    print(&tail);
    cout << endl;
    return 0;
}
