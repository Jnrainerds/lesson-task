#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define CLEAR(a) memset((a),0,sizeof((a)))

using namespace std;

const int maxn = 1e5;
vector<int> a[maxn];
int n;

void init();
void solve();
void outp();

int main()
{
    while (cin >> n)
    {
        init();
        solve();
        outp();
    }
    return 0;
}

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        a[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        a[k / 10].push_back(k);
    }
}

void solve()
{
    for (int i = 0; i < maxn; i++)
    {
        sort(&a[i][0], &a[i][0] + a[i].size());
    }
}

void outp()
{
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << ' ';
        }
    }
    cout << endl;
}

