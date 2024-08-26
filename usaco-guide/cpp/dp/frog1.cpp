#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() { 
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i  = 0; i < N; i++) { cin >> H[i]; }
	vector<int> MinCostToReachStonei(N, INT_MAX);
	// start at stone 0 so we incur a cost of 0
	MinCostToReachStonei[0] = 0;
	for (int i = 1; i < N; i++) {
		if (i - 1 >= 0) {
			MinCostToReachStonei[i] = min(MinCostToReachStonei[i], MinCostToReachStonei[i-1] + abs(H[i] - H[i-1]));
		}

		if (i - 2 >= 0) {
			MinCostToReachStonei[i] = min(MinCostToReachStonei[i], MinCostToReachStonei[i-2] + abs(H[i] - H[i-2]));
		}
	}
	cout << MinCostToReachStonei[N-1] << endl;
	return 0;
}