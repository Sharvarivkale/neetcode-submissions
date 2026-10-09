class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();

        // Early exit: word longer than the board
        if ((int)word.size() > rows * cols) return false;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int i) {
        if (i == (int)word.size()) return true;

        if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()
            || board[r][c] != word[i]) {
            return false;
        }

        char tmp = board[r][c];
        board[r][c] = '#';  // mark visited

        bool found = dfs(board, word, r + 1, c, i + 1) ||
                     dfs(board, word, r - 1, c, i + 1) ||
                     dfs(board, word, r, c + 1, i + 1) ||
                     dfs(board, word, r, c - 1, i + 1);

        board[r][c] = tmp;  // backtrack
        return found;
    }
};