class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto &word : words)
            mp[word]++;

        vector<string> wordX;
        for (auto &it : mp)
            wordX.push_back(it.first);

        sort(wordX.begin(), wordX.end(),
             [&](const string &a, const string &b) {
                 if (mp[a] == mp[b])
                     return a < b;          // Lexicographically smaller first
                 return mp[a] > mp[b];  // Higher frequency first
             });

        wordX.resize(k);
        return wordX;
    }
};
