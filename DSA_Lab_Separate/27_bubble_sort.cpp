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
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }

    cout << "Sorted array: ";
    for(int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}