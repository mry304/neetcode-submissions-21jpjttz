class PrefixTree {
private:
    array<PrefixTree*, 26> children;
    bool terminal;
public:
    PrefixTree() : terminal(false) {
        children.fill(nullptr);
    }
    
    void insert(string_view word) {
        int charNum = word[0] - 'a';
        PrefixTree* next = children[charNum];
        if (next == nullptr) {
            next = new PrefixTree();
            children[charNum] = next;
        }
        if (word.length() == 1) {
            next->terminal = true;
            return;
        }

        return next->insert(word.substr(1));
    }
    
    bool search(string_view word) {
        if (word.length() == 0) return terminal;

        int charNum = word[0] - 'a';
        if (children[charNum] == nullptr) return false;

        return children[charNum]->search(word.substr(1));
    }
    
    bool startsWith(string_view prefix) {
        if (prefix.length() == 0) return true;

        int charNum = prefix[0] - 'a';

        if (children[charNum] == nullptr) return false;
        
        return children[charNum]->startsWith(prefix.substr(1));
    }
};
