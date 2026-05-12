#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    double p, w, ratio;
};

// Comparator (sort by ratio descending)
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    cout << "Number of Items: ";
    cin >> n;

    int maxCapacity;
    cout << "Max Capacity: ";
    cin >> maxCapacity;

    Item a[n];

    // Input profit and weight
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> a[i].p >> a[i].w;
        a[i].ratio = a[i].p / a[i].w;
    }

    // Sort items by ratio
    sort(a, a + n, compare);

    double profit = 0.0;
    double weight = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (weight + a[i].w <= maxCapacity)
        {
            weight += a[i].w;
            profit += a[i].p;
        }
        else
        {
            double available_space = maxCapacity - weight;
            profit += a[i].p * (available_space / a[i].w);
            weight = maxCapacity;
            break;
        }
    }

    cout << "Maximum Profit: " << profit << endl;
     cout << "Maximum weight: " << weight << endl;

    return 0;
}