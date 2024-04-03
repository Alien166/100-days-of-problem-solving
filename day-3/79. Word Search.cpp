#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }

private:
    bool search(vector<vector<char>>& board, const string& word, int index, int i, int j) {
        if (index == word.length())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
            return false;
        char temp = board[i][j];
        board[i][j] = '*'; // Mark as visited
        bool found = search(board, word, index + 1, i + 1, j) ||
                     search(board, word, index + 1, i - 1, j) ||
                     search(board, word, index + 1, i, j + 1) ||
                     search(board, word, index + 1, i, j - 1);
        board[i][j] = temp; // Restore original value
        return found;
    }
};
