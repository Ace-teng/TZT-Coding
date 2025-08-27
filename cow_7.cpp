#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        pre[i] = (pre[i - 1] + num) % 7;
    }

    vector<int> first(7, -1);
    vector<int> last(7, -1);
    for (int i = n; i >= 0; --i) {
        first[pre[i]] = i;
    }
    first[0] = 0; // 显式处理从头开始的子序列

    for (int i = 0; i <= n; ++i) {
        last[pre[i]] = i;
    }

    int max_len = 0;
    for (int i = 0; i < 7; ++i) {
        if (first[i] != -1) {
            max_len = max(max_len, last[i] - first[i]);
        }
    }

    cout << max_len << endl;
    return 0;
}