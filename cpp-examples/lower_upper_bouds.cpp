#include <bits/stdc++.h>

using namespace std;

int FindLowerBound(const vector<int>& arr, int num) {
    if (!arr.size())
        return -1;
    int lower = 0;
    int upper = arr.size() - 1;
    int idx = arr.size();
    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;
        if (arr[mid] >= num) {
            upper = mid -1;
            idx = mid;
        }
        else {
            lower = mid+1;
        }
    }
    return idx;
}

int main() {
    vector<int> arr = {1, 2, 6, 6, 10, 12};
    int num = 10;
    int lower = FindLowerBound(arr, num);
    int upper = FindLowerBound(arr, num+1) - 1;
    if (lower <= upper)
        cout<< "lower =" << lower << "upper =" << upper<<endl;
    else
        cout <<"Element not present"<<endl;
    return 0;
}