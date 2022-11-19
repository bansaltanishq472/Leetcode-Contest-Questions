#include<bits/stdc++.h>
using namespace std;
// int gcdf(int a, int b) {
// 	if (b == 0) return a;
// 	return gcdf(b , a % b);
// }
// void SubarrayLcm(vector<int>& nums, int k) {
// 	int n = nums.size();
// 	int cnt = 0;
// 	for (int i = 0 ; i < n ; i++) {
// 		int lcm = nums[i];
// 		if (lcm == k) cnt++;
// 		for (int j = i + 1 ; j < n ; j++) {
// 			int gcd = gcdf(lcm, nums[j]);
// 			lcm = (lcm * nums[j]) / gcd;
// 			if (lcm > k) break;
// 			if (lcm == k) cnt++;
// 		}
// 	}
// 	cout << cnt << endl;
// }
int SubarrayLCM(vector<int>& nums, int k) {
	int n = nums.size();
	int cnt = 0;
	for (int i = 0; i < n ; i++) {
		int lcm = nums[i];
		if (lcm == k) cnt++;
		for (int j = i + 1 ; j < n ; j++) {
			int gcd = __gcd(lcm, nums[j]);
			lcm = (lcm * nums[j]) / gcd;
			if (lcm > k) break;
			if (lcm == k) cnt++;
		}
	}
	return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0 ; i < n ; i++) {
		cin >> nums[i];
	}
	int k;
	cin >> k;
	SubarrayLCM(nums, k);
	// cout << ans << endl;
	return 0;
}