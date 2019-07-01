//验证回文串
/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool is_alpha(char c)
{
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= 'a' && c <= 'z') return true;
    if(c >= '0' && c <= '9') return true;
    return false;
}
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int length = s.size();
        int i = 0,j = length-1;
        while(i < j)
        {
            while((!is_alpha(s[i])) && i < j) i++;
            while((!is_alpha(s[j])) && i < j) j--;
            if(s[i] != s[j] && i < j) return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "race a car";
	Solution s;
	cout << s.isPalindrome(s1) << endl;
	cout << s.isPalindrome(s2) << endl;
}