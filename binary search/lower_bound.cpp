#include <iostream>
#include <set>
#include <map>

int main() {
    // Using lower_bound with std::set
    std::set<int> s = {1, 3, 5, 7, 9};
    auto it1 = s.lower_bound(4); // returns iterator to 5
    auto it2 = s.lower_bound(6); // returns iterator to 7
    std::cout << *it1 << " " << *it2 << std::endl; // output: 5 7

    // Using lower_bound with std::map
    std::map<int, std::string> m = {{1, "one"}, {3, "three"}, {5, "five"}, {7, "seven"}, {9, "nine"}};
    auto it3 = m.lower_bound(4); // returns iterator to key-value pair (5, "five")
    auto it4 = m.lower_bound(6); // returns iterator to key-value pair (7, "seven")
    std::cout << it3->second << " " << it4->second << std::endl; // output: five seven

    return 0;
}
