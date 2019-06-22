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
        //在位置pos插入元素e
        bool Insert(Elemtype e, int pos);
        //删除pos上的元素
        bool Delete(int pos);
        //获取pos上的元素
        Elemtype GetElement(int pos);
        //判空
        bool isEmpty();
        //判满
        bool isFull();
        //获取长度
        int GetLength();
        //打印数组
        void Print();
};

Array::Array()
{
    length = 0;
}

//在位置pos插入元素e
bool Array::Insert(Elemtype e, int pos)
{
    if(length >= MAX_SIZE)
    {
        cout << "Oversize!" << endl;
        return false;
    }
    else if(pos < 1 || pos > length+1)//插入位置不合法
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

//删除pos上的元素
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

//获取pos上的元素
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

//判空
bool Array::isEmpty()
{
    if(length == 0)
        return true;
    else return false;
}

//判满
bool Array::isFull()
{
    if(length == MAX_SIZE)
        return true;
    else return false;
}

//获取长度
int Array::GetLength()
{
    return length;
}

//打印数组
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
    cout << "获取元素：" << array.GetElement(3) << endl;

}

