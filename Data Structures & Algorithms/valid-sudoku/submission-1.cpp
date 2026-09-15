class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char value = board[i][j];

                if (value == '.') {
                    continue;
                }

                int box = (i / 3) * 3 + (j / 3);

                if (rows[i].count(value)) {
                    return false;
                }

                if (cols[j].count(value)) {
                    return false;
                }

                if (boxes[box].count(value)) {
                    return false;
                }

                rows[i].insert(value);
                cols[j].insert(value);
                boxes[box].insert(value);
            }
        }

        return true;
    }
};