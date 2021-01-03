class Trie {
private:
    Trie * next[26];
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie() : isEnd(false){
        memset(next, 0x00, 26 * sizeof(Trie *));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.length();
        Trie * temp = this;
        for(int i = 0; i < n; ++i) {
            if(temp->next[word[i] - 'a'] == nullptr)
                temp->next[word[i] - 'a'] = new Trie();
            temp = temp->next[word[i] - 'a'];
        }
        temp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.length();
        Trie * temp = this;
        for(int i = 0; i < n; ++i) {
            if(temp->next[word[i] - 'a'] == nullptr) return false;
            temp = temp->next[word[i] - 'a'];
        }
        return temp->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.length();
        Trie * temp = this;
        for(int i = 0; i < n; ++i) {
             if(temp->next[prefix[i] - 'a'] == nullptr) 
                return false;
            temp = temp->next[prefix[i] - 'a'];
        }
        return true;
    }
};

/*
["Trie","insert","search","search","startsWith","insert","search"]
[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]
["Trie","insert","search","search","startsWith","startsWith","insert","search","startsWith","insert","search","startsWith"]
[[],["ab"],["abc"],["ab"],["abc"],["ab"],["ab"],["abc"],["abc"],["abc"],["abc"],["abc"]]
["Trie","insert","insert","insert","insert","insert","insert","search","search","search","search","search","search","search","search","search","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith"]
[[],["app"],["apple"],["beer"],["add"],["jam"],["rental"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"]]
*/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */