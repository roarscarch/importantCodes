vector<vector<int>> findSubarraysWithXOR(vector<int>& A, int target_xor) {
    int n = A.size();
    vector<int> P(n);
    unordered_map<int, vector<int>> xor_map;
    vector<vector<int>> result;

    // Compute prefix XOR array P
    P[0] = A[0];
    for (int i = 1; i < n; i++) {
        P[i] = P[i-1] ^ A[i];
    }

    // Store indices of prefix XOR array in hash table
    xor_map[0].push_back(-1); // Special case for subarrays starting at index 0
    for (int i = 0; i < n; i++) {
        xor_map[P[i]].push_back(i);
    }

    // Search for subarrays with XOR equal to target_xor
    for (int j = 0; j < n; j++) {
        int complement_xor = P[j] ^ target_xor;
        if (xor_map.count(complement_xor)) {
            for (int i : xor_map[complement_xor]) {
                result.push_back({i+1, j});
            }
        }
    }

    return result;
}
/*
To find all subarrays with a given XOR in a subarray, you can use the prefix XOR array approach in combination with a hash table or map.

Here's the basic idea:

Compute the prefix XOR array P for the given input array A.
For each index i in the prefix XOR array P, store the index i in a hash table or map, along with the value P[i]. This effectively stores the XOR of all elements up to index i and its corresponding index i in the prefix XOR array.
For each index j in the prefix XOR array P, look up the value P[j] XOR target_xor in the hash table or map. If such a value exists, then there is a subarray with XOR equal to target_xor that ends at index j. To find all such subarrays, you can simply iterate over the corresponding indices i in the hash table or map and compute the subarray [i+1, j].
*/