class TrieNode {
public:
    vector<TrieNode*> children;
    bool is_leaf;
    // Initialize your data structure here.
    TrieNode(int num_chars = 26): children(num_chars,NULL), is_leaf(false){
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p =root;
        for(char c : word)
        {
            if(!p->children[c-'a'])
                p->children[c-'a'] = new TrieNode();
            p = p->children[c-'a'];
        }
        p->is_leaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = find(word);
        return p && p->is_leaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = find(prefix);
        return p!=NULL;
    }

private:
    TrieNode* root;
    TrieNode* find(string word)
    {
        TrieNode *p = root;
        for(char c: word)
        {
            if(p->children[c-'a'])
                 p = p->children[c-'a'];
            else
                return NULL;
        }
        return p;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
