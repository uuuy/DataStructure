//查找数组中第二小的数
#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

template <class T>
int getArrayLen(T& array){
//使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度
return (sizeof(array) / sizeof(array[0]));

}

int secondmin(int array[], int len){
    int first = INT_MAX;
    int second = INT_MAX;
    for(int i = 0; i < len; i++){
        if(array[i] < first){
            second = first;
            first = array[i];
        }
        else if(array[i] < second && array[i] != first){
            second = array[i];
        }
    }
    return second;
}

int main(){
    int array[] = {10,9,8,5,7,6,2,1};
    int len = getArrayLen(array);
    int second = secondmin(array, len);
    cout << "the second min is " << second << endl;
}
