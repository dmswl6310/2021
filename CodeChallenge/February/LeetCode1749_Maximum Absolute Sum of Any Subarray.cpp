#include<iostream>
#include<vector>
using namespace std;
int maxAbsoluteSum(vector<int>& nums);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> nums = { 1,-3,2,3,-4 };
	cout << maxAbsoluteSum(nums);
}
int maxAbsoluteSum(vector<int>& nums) {
	vector<int>dpMax;
	vector<int>dpMin;
	dpMax.assign(nums.begin(), nums.end());
	dpMin.assign(nums.begin(), nums.end());

	int numMax=dpMax[0];
	int numMin = dpMin[0];
	for (int i = 1; i < nums.size(); i++) {
		if (dpMax[i - 1] > 0)dpMax[i] += dpMax[i - 1];
		if (dpMax[i] > numMax) numMax = dpMax[i];

		if (dpMin[i - 1] < 0)dpMin[i] += dpMin[i - 1];
		if (dpMin[i] < numMin) numMin = dpMin[i];
	}

	return numMax > (-numMin) ? numMax : -numMin;
	
}