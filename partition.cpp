/*
分割回文串

给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<string>> str;
    vector<string> tmp;

    bool isPalindrome(string s) {
        //判断
        int length = s.length();
        int i = 0, j = length - 1;
        while(i < j)
        {
            if(s[i] != s[j] && i < j) return false;
            i++;
            j--;
        }
        return true;
    }

    void search(string s, int index) {
        if(index == s.length()) {//回溯终止条件
            str.push_back(tmp);
            return;
        }
        for(int i = index; i < s.length(); i++) {
            string substr = s.substr(index, i-index+1);
            if(isPalindrome(substr)) {
                tmp.push_back(substr);
                cout << "tmp in = ";
                for(auto c:tmp) {
                    cout << c << " ";
                }
                cout << endl;
                search(s, i+1);
                tmp.pop_back();//回溯
                cout << "tmp out = ";
                for(auto c:tmp) {
                    cout << c << " ";
                }
                cout << endl;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        //回溯法(DFS)
        search(s, 0);
        return str;
    }
};
int main()
{
	Solution sl;
	string s = "aab";
	sl.partition(s);
	for(int i = 0; i < sl.str.size(); i++) {
	    for(auto ss:sl.str[i]) {
            cout << ss << " ";
        }
        cout << endl;
	}
}
