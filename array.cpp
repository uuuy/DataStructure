#include<iostream>
using namespace std;

#define MAX_SIZE 20

typedef int Elemtype;

class Array
{
    private:
        Elemtype data[MAX_SIZE];
        int length;

    public:
        Array();
        //~Array();
        //��λ��pos����Ԫ��e
        bool Insert(Elemtype e, int pos);
        //ɾ��pos�ϵ�Ԫ��
        bool Delete(int pos);
        //��ȡpos�ϵ�Ԫ��
        Elemtype GetElement(int pos);
        //�п�
        bool isEmpty();
        //����
        bool isFull();
        //��ȡ����
        int GetLength();
        //��ӡ����
        void Print();
};

Array::Array()
{
    length = 0;
}

//��λ��pos����Ԫ��e
bool Array::Insert(Elemtype e, int pos)
{
    if(length >= MAX_SIZE)
    {
        cout << "Oversize!" << endl;
        return false;
    }
    else if(pos < 1 || pos > length+1)//����λ�ò��Ϸ�
    {
        cout << "Illegal Position!" << endl;
        return false;
    }
    else
    {
        for(int i = length-1; i > pos; i--)
        {
            data[i+1] = data[i];
        }
        data[pos-1] = e;
        length++;
    }
    return true;
}

//ɾ��pos�ϵ�Ԫ��
bool Array::Delete(int pos)
{
    if(length == 0)
    {
        cout << "Empty!" << endl;
        return false;
    }
    else if(pos < 1 || pos > length)
    {
        cout << "Illegal Position!" << endl;
        return false;
    }
    else
    {
        for(int i = pos-1; i <= length-1; i++)
        {
            data[i] = data[i+1];
        }
        length--;
    }
    return true;
}

//��ȡpos�ϵ�Ԫ��
Elemtype Array::GetElement(int pos)
{
    if(length == 0)
    {
        cout << "Empty!" << endl;
        return false;
    }
    else if(pos < 1 || pos > length)
    {
        cout << "Illegal Position!" << endl;
        return false;
    }
    else
    {
        return data[pos-1];
    }

}

//�п�
bool Array::isEmpty()
{
    if(length == 0)
        return true;
    else return false;
}

//����
bool Array::isFull()
{
    if(length == MAX_SIZE)
        return true;
    else return false;
}

//��ȡ����
int Array::GetLength()
{
    return length;
}

//��ӡ����
void Array::Print()
{
    for(int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }
}

int main()
{
    Array array;
    for(int i = 1; i < 6; i++)
    {
        array.Insert(i, i);
    }
    array.Print();
    cout << endl;
    array.Delete(3);
    array.Print();
    cout << endl;
    cout << "��ȡԪ�أ�" << array.GetElement(3) << endl;

}

