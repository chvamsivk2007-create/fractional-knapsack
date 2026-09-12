#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item items[], int n) {
    sort(items, items + n, compare);

    double totalValue = 0.0;
    int remainingCapacity = W;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        }
        else {
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            remainingCapacity = 0;
            break; 
        }
    }

    return totalValue;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    double maxValue = fractionalKnapsack(W, items, n);

    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
