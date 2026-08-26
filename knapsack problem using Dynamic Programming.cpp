#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n + 1), value(n + 1);

    cout << "Enter weights of items:\n";
    for (int i = 1; i <= n; i++)
        cin >> weight[i];

    cout << "Enter values of items:\n";
    for (int i = 1; i <= n; i++)
        cin >> value[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i] <= w)
                dp[i][w] = max(dp[i - 1][w],
                               value[i] + dp[i - 1][w - weight[i]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "\nMaximum Profit = " << dp[n][W] << endl;

    cout << "Selected items: ";
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weight[i];
        }
    }

    return 0;
}
