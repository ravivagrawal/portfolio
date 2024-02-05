#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int maxShared(int friends_nodes, vector<int>& friends_from, vector<int>& friends_to, vector<int>& friends_weight) {
    unordered_map<pair<int, int>, unordered_set<int>> interests;

    // Create a map to store interests for each node pair
    for (int i = 0; i < friends_from.size(); ++i) {
        pair<int, int> nodePair = make_pair(friends_from[i], friends_to[i]);
        interests[nodePair].insert(friends_weight[i]);
    }

    // Find the maximum number of shared interests
    int maxSharedInterests = 0;
    for (const auto& pairInterests : interests) {
        maxSharedInterests = max(maxSharedInterests, static_cast<int>(pairInterests.second.size()));
    }

    // Find all node pairs with the maximum number of shared interests
    vector<pair<int, int>> maxSharedPairs;
    for (const auto& pairInterests : interests) {
        if (pairInterests.second.size() == maxSharedInterests) {
            maxSharedPairs.push_back(pairInterests.first);
        }
    }

    // Calculate the maximal product
    int maximalProduct = friends_nodes * friends_nodes;
    for (const auto& pair : maxSharedPairs) {
        maximalProduct = max(maximalProduct, pair.first * pair.second);
    }

    return maximalProduct;
}

int main() {
    int friends_nodes = 4;
    int friends_edges = 5;
    vector<int> friends_from = {1, 1, 2, 2, 2};
    vector<int> friends_to = {2, 2, 3, 3, 4};
    vector<int> friends_weight = {2, 3, 1, 3, 4};

    int result = maxShared(friends_nodes, friends_from, friends_to, friends_weight);
    cout << result << endl;

    return 0;
}
