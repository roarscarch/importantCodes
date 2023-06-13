/*
I apologize for the confusion. You are right, in the word break problem, the dictionary contains individual words, not substrings. Therefore, we don't need to check for substrings within the dictionary.

To clarify the process using BFS:

We start by considering each index in the input string as a potential starting point for a word.
For each index, we iterate through the dictionary and check if a word starting from that index matches any word in the dictionary.
If we find a match, we move to the next index and repeat the process until we reach the end of the string.
If we successfully reach the end of the string, it means we have found a valid segmentation using words from the dictionary.
If we cannot find a valid segmentation using the given dictionary, we return false.
*/
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    queue<int> q;
    vector<bool> visited(s.length(), false);
    q.push(0);

    while (!q.empty()) {
        int start = q.front();
        q.pop();

        if (!visited[start]) {
            for (int end = start + 1; end <= s.length(); end++) {
                string word = s.substr(start, end - start);
                if (dict.find(word) != dict.end()) {
                    q.push(end);
                    if (end == s.length())
                        return true;
                }
            }
            visited[start] = true;
        }
    }

    return false;
}