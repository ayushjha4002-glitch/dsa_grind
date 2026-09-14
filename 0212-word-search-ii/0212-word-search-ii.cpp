class Solution {
public:

    class TrieNode {
    public:
        TrieNode* child[26];
        string word;

        TrieNode() {
            word = "";

            for(int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };

    TrieNode* root;
    vector<string> ans;

    int n, m;

    void insert(string word) {
        TrieNode* node = root;

        for(char ch : word) {
            int index = ch - 'a';

            if(node->child[index] == NULL) {
                node->child[index] = new TrieNode();
            }

            node = node->child[index];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int x, int y,
             TrieNode* node) {

        if(x < 0 || x >= n || y < 0 || y >= m) {
            return;
        }

        if(board[x][y] == '#') {
            return;
        }

        char ch = board[x][y];
        int index = ch - 'a';

        if(node->child[index] == NULL) {
            return;
        }

        node = node->child[index];

        if(node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[x][y] = '#';

        dfs(board, x - 1, y, node); // up
        dfs(board, x + 1, y, node); // down
        dfs(board, x, y - 1, node); // left
        dfs(board, x, y + 1, node); // right

        board[x][y] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        n = board.size();
        m = board[0].size();

        root = new TrieNode();

        for(string word : words) {
            insert(word);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};