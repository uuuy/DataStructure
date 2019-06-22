#include<iostream>
using namespace std;

typedef int Elemtype;

struct Node
{
    Elemtype data;
    struct Node *next;
};

class LinkList
{
    private:
        Node *head;

    public:
        LinkList();
        ~LinkList();
        //����
        void Creat();
        //�п�
        bool isEmpty();
        //����
        void Insert(Elemtype e, int pos);
        //ɾ��
        void Delete(int pos);
        //����
        Elemtype Find(int pos);
        //����
        void Print();
        //����
        int GetLength();
};
//��ʼ��
LinkList::LinkList()
{
    head = new Node;
    head->next = NULL;
}

//����
LinkList::~LinkList()
{
    delete head;
}

//����
void LinkList::Creat()
{
    Node *p = head;
    Node *temp;
    int n;
    cout << "�����������";
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cout << "�������" << i << "��ֵ��";
        temp = new Node;
        cin >> temp->data;
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
}

//�п�
bool LinkList::isEmpty()
{
    if(head->next == NULL)
        return true;
    return false;
}

//����
void LinkList::Insert(Elemtype e, int pos)
{
    Node *p = head;
    Node *temp = new Node;
    temp->data = e;
    temp->next = NULL;

    if(pos < 1 || pos > GetLength()+1)
    {
        cout << "Illegal Position!" << endl;
    }
    else if(pos == 1)//ͷ��
    {
        temp->next = p->next;
        p->next = temp;
    }
    else if(pos == GetLength()+1)//β��
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    else
    {
        int i = 0;
        while(p->next != NULL)
        {
            if(i == pos-1)
            {
                temp->next = p->next;
                p->next = temp;
            }
            p = p->next;
            i++;
        }
    }
}

//ɾ��
void LinkList::Delete(int pos)
{
    Node *p = head, *temp;
    int i = 0;
    if(pos < 1 || pos > GetLength())
    {
        cout << "Illegal Position!" << endl;
    }
    else if(pos == GetLength())//ɾ�����һ��Ԫ��
    {
        while(p->next != NULL)
        {
            temp = p;//β�ڵ�ǰһ��
            p = p->next;
        }
        temp->next = NULL;
        delete p;
    }
    else
    {
        while(p->next != NULL)
        {
            if(i == pos-1)
            {
                temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            p = p->next;
            i++;
        }
    }
}

//����
Elemtype LinkList::Find(int pos)
{
    Node *p = head;
    int i = 0;
    while(p->next != NULL)
    {
        if(i == pos)
        {
            return p->data;
        }
        p = p->next;
        i++;
    }
}

//����
void LinkList::Print()
{
    Node *p = head;
    while(p->next != NULL)
    {
        p = p->next;
        cout<< p->data << " ";
    }
    cout << endl;
}

//����
int LinkList::GetLength()
{
    Node *p = head;
    int length = 0;
    while(p->next != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}

int main()
{
    LinkList l;
    l.Creat();
    l.Print();
    l.Insert(6, 1);
    l.Insert(7, 7);
    l.Insert(8, 5);
    l.Print();
    l.Delete(3);
    l.Print();
    cout << "���ĸ�λ��Ԫ��Ϊ��" << l.Find(4) << endl;
    cout << "����Ϊ��" << l.GetLength() << endl;
}
