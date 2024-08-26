#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() { 
	int n;
	cin >> n;
	vector<long long> NumWaysAddsToi(n*n);
	
	// There is only one way to achieve a sum of 0, which is by not rolling any dice
	NumWaysAddsToi[0] = 1;

	for (int i = 1; i <= n; i++) {
		// Iterate over each possible dice roll outcome (from 1 to 6)
		for (int j = 1; j <= 6; j++) {
			// Check if it's possible to subtract j from i without going negative
			// i - j represents the sum that would need to be achieved before this roll
			if (i - j >= 0) { 
				// If the sum i - j is valid (non-negative), add the number of ways
				// to achieve the sum i - j to the number of ways to achieve the sum i
				NumWaysAddsToi[i] += NumWaysAddsToi[i - j]; 
			}
		}
		NumWaysAddsToi[i] %= 1000000007;
	}
	cout << NumWaysAddsToi[n] << endl;
}
