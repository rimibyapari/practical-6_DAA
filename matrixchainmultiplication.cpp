#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    int numMatrices;
    cout << "Enter the number of matrices: ";
    cin >> numMatrices;

    if (numMatrices < 1) {
        cout << "Number of matrices must be at least 1." << endl;
        return 0;
    }

    vector<int> dimensions(numMatrices + 1);

    cout << "Enter the dimensions sequence (separated by spaces).\n";
    cout << "For example, for 3 matrices of sizes 10x20, 20x30, 30x40,
enter: 10 20 30 40\n";
    cout << "Dimensions: ";
    for (int i = 0; i <= numMatrices; i++) {
        cin >> dimensions[i];
    }

    int minOperations = matrixChainOrder(dimensions);
    cout << "\nMinimum number of scalar multiplications required: " <<
minOperations << endl;

    return 0;
}

