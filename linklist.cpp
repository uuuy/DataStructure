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
        //创建
        void Creat();
        //判空
        bool isEmpty();
        //插入
        void Insert(Elemtype e, int pos);
        //删除
        void Delete(int pos);
        //查找
        Elemtype Find(int pos);
        //遍历
        void Print();
        //长度
        int GetLength();
};
//初始化
LinkList::LinkList()
{
    head = new Node;
    head->next = NULL;
}

//销毁
LinkList::~LinkList()
{
    delete head;
}

//创建
void LinkList::Creat()
{
    Node *p = head;
    Node *temp;
    int n;
    cout << "请输入个数：";
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cout << "请输入第" << i << "个值：";
        temp = new Node;
        cin >> temp->data;
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
}

//判空
bool LinkList::isEmpty()
{
    if(head->next == NULL)
        return true;
    return false;
}

//插入
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
    else if(pos == 1)//头插
    {
        temp->next = p->next;
        p->next = temp;
    }
    else if(pos == GetLength()+1)//尾插
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

//删除
void LinkList::Delete(int pos)
{
    Node *p = head, *temp;
    int i = 0;
    if(pos < 1 || pos > GetLength())
    {
        cout << "Illegal Position!" << endl;
    }
    else if(pos == GetLength())//删除最后一个元素
    {
        while(p->next != NULL)
        {
            temp = p;//尾节点前一个
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

//查找
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

//遍历
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

//长度
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
    cout << "第四个位置元素为：" << l.Find(4) << endl;
    cout << "长度为：" << l.GetLength() << endl;
}
