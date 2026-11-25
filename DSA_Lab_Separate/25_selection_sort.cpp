#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n - 1; i++)
    {
        int mn = i;
        for(int j = i + 1; j < n; j++)
            if(a[j] < a[mn])
                mn = j;

        swap(a[i], a[mn]);
    }

    cout << "Sorted array: ";
    for(int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}