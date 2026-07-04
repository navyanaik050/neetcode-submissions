
class TireNode {
    public :
       
        TireNode* children[26];
        bool endOfWord;
        TireNode(){ 
            for (int i=0; i<26; i++){
                children[i] = nullptr;
            }
            endOfWord = false;
        }
};
class PrefixTree {
    TireNode* root;
public:
    PrefixTree() {
        root = new TireNode();
    }
    
    void insert(string word) {
        TireNode* cur = root;
        for(auto c : word){
            int i = c - 'a';
            if (cur->children[i] == nullptr){
                cur->children[i] = new TireNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TireNode* cur = root;
        for(auto c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TireNode* cur = root;
        for(auto c : prefix){
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i];
        }
        return true;
        
    }
};
