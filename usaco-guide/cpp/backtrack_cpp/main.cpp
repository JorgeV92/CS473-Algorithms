#include <iostream>
#include "backtrack.h"

using namespace std;


int main () {
    // Apples question
    int n;
    cin >> n;
    vector<long long> weights(n);
    for (int i = 0; i < n; i++) { cin >> weights[i]; }
    cout << recurse_apples(0, 0, 0, n, weights) << endl;
    // cout << bitmask_apples(weights) << endl;

    return 0;
}