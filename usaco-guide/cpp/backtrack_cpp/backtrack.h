#ifndef BACKTRACK_H
#define BACKTRACK_H

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

/*
There are n apples with known weights. Your task is to divide the apples into 
two groups so that the difference between the weights of the group is minimal.
*/

// Generating subsets recursively
ll recurse_apples(int index, ll sum1, ll sum2, int n, vector<ll>& weights) {
    // Base case
    // Added all the apples so return the absolute difference
    if (index == n) { return abs(sum1 - sum2); }

    // Recurse: Try to add the current apple to either the first or second set
    return min(recurse_apples(index + 1, sum1 + weights[index], sum2, n, weights), recurse_apples(index + 1, sum1, sum2 + weights[index], n, weights));
}

// Alternative solution 
// Generating subsets with bitmasks
    // 1 << x for an integer x is another way of writing 2^x, which in binary has only
    // the xth bit on

    //  mask & (1 << x) will return a positive value only if the x'th bit is
    // turned on in mask.
    
ll bitmask_apples(vector<ll>& weights) {
    int n = weights.size();
    ll ans = INT64_MAX;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum1 = 0;
        ll sum2 = 0;
        for (int i = 0; i < n; i++) {
            // is the ith bit on
            if (mask & (1  << i)) {
                // include the apple in sum1
                sum1 += weights[i];
            } else {
                sum2 += weights[i];
            }
        }
        ans = min(ans, abs(sum1 - sum2));
    }
    return ans;
}


#endif // BACKTRACK_H
