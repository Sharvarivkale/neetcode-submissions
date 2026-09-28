class CountSquares {
public:
    map<pair<int, int>, int> freq;
    vector<vector<int>> points;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        freq[{point[0], point[1]}]++;
        points.push_back(point);
    }
    
    int count(vector<int> point) {
        int x = point[0];   // ← You were missing this
        int y = point[1];

        int ans = 0;

        for (auto p : points) {
            int x2 = p[0];
            int y2 = p[1];

            // Same x or same y cannot make a square
            if (x2 == x || y2 == y)
                continue;

            // Distance must be equal
            if (abs(x2 - x) != abs(y2 - y))
                continue;

            // Other two corners
            int x3 = x2;
            int y3 = y;

            int x4 = x;
            int y4 = y2;

            ans += freq[{x3, y3}] * freq[{x4, y4}];
        }

        return ans;
    }
};