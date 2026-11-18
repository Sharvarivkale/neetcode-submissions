
class PrefixTree {
public:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    Node* root;

    PrefixTree() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (curr->children[index] == NULL) {
                curr->children[index] = new Node();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        Node* curr = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (curr->children[index] == NULL) {
                return false;
            }

            curr = curr->children[index];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* curr = root;

        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';

            if (curr->children[index] == NULL) {
                return false;
            }

            curr = curr->children[index];
        }

        return true;
    }
};
