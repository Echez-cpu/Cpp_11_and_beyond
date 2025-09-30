#include <iostream>
using namespace std;

int jumps(int flagHeight, int bigJump) {
    // Number of big jumps we can take
    int bigJumps = flagHeight / bigJump;
    // Remaining height to cover with 1-unit jumps
    int remaining = flagHeight % bigJump;

    return bigJumps + remaining;
}

int main() {
    int flagHeight, bigJump;
    cin >> flagHeight >> bigJump;

    cout << jumps(flagHeight, bigJump) << endl;
    return 0;
}




// another one

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int getMaxUniqueServer(vector<int>& capacities) {
    sort(capacities.begin(), capacities.end()); // sort ascending
    unordered_set<int> used; // track unique capacities

    for (int cap : capacities) {
        if (cap > 1 && used.find(cap - 1) == used.end()) {
            used.insert(cap - 1); // prefer smaller adjustment
        } 
        else if (used.find(cap) == used.end()) {
            used.insert(cap);
        } 
        else if (used.find(cap + 1) == used.end()) {
            used.insert(cap + 1);
        }
        // else can't place this server uniquely
    }

    return used.size();
}

int getMaxUniqueServer2(vector<int>& capacities) {
    sort(capacities.begin(), capacities.end()); // sort ascending
    unordered_set<int> used; // track unique capacities; it eliminates duplicates and also doesn't order things

    for (size_t i = 0; i < capacities.size(); i++) {
        int cap = capacities[i];

        if (cap > 1 && used.find(cap - 1) == used.end()) {
            used.insert(cap - 1); // prefer smaller adjustment
        } 
        else if (used.find(cap) == used.end()) {
            used.insert(cap);
        } 
        else if (used.find(cap + 1) == used.end()) {
            used.insert(cap + 1);
        }
        // else can't place this server uniquely
    }

    return used.size();
}


int main() {
    vector<int> capacities = {1, 1, 4, 4, 1, 4};
    cout << getMaxUniqueServer(capacities) << endl; // Output: 5

    vector<int> test2 = {2, 1, 2, 1};
    cout << getMaxUniqueServer(test2) << endl; // Output: 4

    return 0;
}
