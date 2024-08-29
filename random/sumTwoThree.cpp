#include <bits/stdc++.h>
#include <vector>
using namespace std;



void SumTwoThree(vector<int>& A) {
	int n = A.size();
	sort(A.begin(), A.end());	
	int l = 0, r = n - 1;
	while (l < r) {
		if (A[l] + A[r] > 0) r--;
		else if (A[l] + A[r] < 0) l++;
		else {
			cout << "True";
			return;
		}
	}
	cout << "False";
}

///////////////////////////////////////////////////
// Test case -> True
// 6
// -3 -1 0 1 3 4
//
// Test case -> False
// 5
// -7 -5 -3 1 2
///////////////////////////////////////////////////

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	SumTwoThree(A);
	return 0;
}