#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bubbleSort(vector<int> &nums) {
	for(int i = 0; i < nums.size(); i++) {
		for(int j = 0; j < nums.size() - 1; j++) {
			if(nums[j] > nums[j+1]) {
				swap(nums[j], nums[j+1]);
			}
		}
	}
	return nums;
}

int main() {
	vector<int> nums = {77, 2, 5, 9, 15, 0, 45};
	vector<int> res = bubbleSort(nums);
	for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}
