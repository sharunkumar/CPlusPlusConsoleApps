// CPlusPlusConsoleApps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

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

int main()
{
	std::cout << find_roll_out("abz", vector<int> {1,3}) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


