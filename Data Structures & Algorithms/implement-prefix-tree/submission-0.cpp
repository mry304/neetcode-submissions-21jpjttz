class PrefixTree {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode(){
            isEndOfWord = false;
            for(int i = 0 ; i < 26; ++i){
                children[i] = nullptr;
            }
        }
    };

    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){
                TrieNode* node = new TrieNode();
                curr->children[c - 'a'] = node;
            }
            curr = curr->children[c- 'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for(char c : word){
            int index = c - 'a';
            if(curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            int index = c - 'a';
            if(curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return true;
    }
};
