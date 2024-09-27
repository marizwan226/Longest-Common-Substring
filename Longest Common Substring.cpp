#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonSubstring(const string& A, const string& B) {
    int n = A.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int maxLength = 0;
    int endingIndex = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endingIndex = i - 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Print the DP table
    cout << "DP Table:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // Return the longest common substring
    return A.substr(endingIndex - maxLength + 1, maxLength);
}

int main() {
    string A = "ABAB";
    string B = "BABA";
    string result = longestCommonSubstring(A, B);
    cout << "Longest Common Substring: " << result << endl;
    return 0;
}
