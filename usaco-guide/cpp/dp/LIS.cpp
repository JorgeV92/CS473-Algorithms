// Source: https://usaco.guide/general/io

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	
	int n; 
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) { cin >> A[i]; }

	vector<int> dp(n, 1);
	vector<int> p(n, -1);
	int ans = dp[0], pos = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && dp[i] < dp[j] + 1) {
				dp[i] =  dp[j] + 1;
				p[i] = j;
			}
			if (dp[i] > ans) {
				ans = dp[i];
				pos = i;
			}
		}
	}


	vector<int> subseq;
	while (pos != -1) {
		subseq.push_back(A[pos]);
		pos = p[pos];
	}

	reverse(subseq.begin(), subseq.end());
	for (int x : subseq) {
		cout << x << " ";
	}

	cout << endl << ans << endl;

	// Binary search
	// vector<int> dp;
	// for (int i : A) {
	// 	int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
	// 	if (pos == dp.size()) {
	// 		dp.push_back(i);
	// 	} else {
	// 		dp[pos] = i;
	// 	}
	// }
	// cout << dp.size() << endl;

	return 0;
}
