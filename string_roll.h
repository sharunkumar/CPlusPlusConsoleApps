#pragma once
#include <string>
#include <vector>

using namespace std;

string find_roll_out(string s, vector<int> roll)
{
	int n = s.length();
    vector<int> prefix_sum(n, 0);
    for (int& i : roll)
    {
        if (i > n) {
	        i = n;
        }
        prefix_sum[i -1]++;
    }
    for (int i = n-2; i >= 0; i--) {
        prefix_sum[i] += prefix_sum[i+1];
    }
    for (int i = 0; i < n; i++) {
        s[i] = (s[i] - 'a' + prefix_sum[i]) % 26 + 'a';
    }
    return s;

}