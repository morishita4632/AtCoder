#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; i++)
    {
        cin >> d.at(i);
    }
    sort(d.begin(), d.end());

    int dansuu = 1;
    int ue = d.at(0);
    for (int i = 1; i < N; i++)
    {
        if (ue < d.at(i))
            dansuu++;
        ue = d.at(i);
    }
    cout << dansuu << endl;
}
