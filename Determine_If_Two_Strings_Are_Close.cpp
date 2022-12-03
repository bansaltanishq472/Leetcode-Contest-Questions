#include<bits/stdc++.h>
using namespace std;

bool Determine_If_Two_Strings_Are_Close(string &s1, string &s2) {
	int length_1 = s1.length();
	int length_2 = s2.length();
	// Edge Case
	if (length_1 != length_2) return false;
	vector<int> f1(26, 0) , f2(26, 0);
	for (int i = 0 ; i < length_1 ; i++) {
		f1[s1[i] - 'a']++;
		f2[s2[i] - 'a']++;
	}
	unordered_map<int, int> mp1, mp2;
	for (int i = 0 ; i < 26 ; i++) {
		mp1[f1[i]]++;
		mp2[f2[i]]++;
	}
	for (int i = 0 ; i < 26 ; i++) {
		if ((f1[i] == 0 && f2[i] != 0) || (f1[i] != 0 && f2[i] == 0)) {
			return false;
		}
		if (mp1[f1[i]] != mp2[f1[i]]) return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s1, s2;
	cin >> s1 >> s2;
	cout << Determine_If_Two_Strings_Are_Close(s1, s2) << endl;
	return 0;
}
