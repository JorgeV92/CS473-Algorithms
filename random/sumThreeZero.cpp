#include <bits/stdc++.h>
#include <vector>
using namespace std;


void SumThreeZero(vector<int>& A) {
	int n = A.size();
	sort(A.begin(), A.end());

	for (int k = 0; k < n; k++) {
		int l = 0, r = n - 1;
		while (l < r) {
			if (l != k && r != k && (A[l] + A[k] + A[r]) == 0) {
				cout << "True";
				return;
			}
			if (A[l] + A[k] + A[r] < 0) 
				l++;
			else 
				r--;
		}
	}
	cout << "False";
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	SumThreeZero(A);
	return 0;
}
