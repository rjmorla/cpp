#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
    int width, partition, temp;

    vector<int> v1;

    cin >> width >> partition;

    for (int i = 0; i < partition; i++) {
        cin >> temp;
        v1.push_back(temp);
    }

    v1.push_back(width);

    for (int i = 0; i <= width; i ++) {
        for (int j = i+1; j <= partition; j++) {
            if (v1[j] - v1[i] > 0) {
                v1.push_back(v1[j] - v1[i]);
            }
        }
    }
    sort (v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] == v1[i+1]) {
            // int it = i+1;
            // v1.erase(v1.begin()+i);
            continue;
        }
        cout << v1[i] << " ";

    }
}