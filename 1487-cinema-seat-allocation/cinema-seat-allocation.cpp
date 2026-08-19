class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        unordered_map<int, int> rowMask; // row -> bitmask of reserved seat cols
        for (auto& s : seats)
            rowMask[s[0]] |= (1 << s[1]);

        const int LEFT  = 0b0000111100; // seats 2,3,4,5
        const int MID   = 0b0011110000; // seats 4,5,6,7
        const int RIGHT = 0b1111000000; // seats 6,7,8,9
        const int ALL   = LEFT | MID | RIGHT; // seats 2..9

        // rows with no reservation at all -> 2 families each
        long long ans = 2LL * (n - (int)rowMask.size());

        for (auto& [row, mask] : rowMask) {
            if ((mask & ALL) == 0) ans += 2;
            else if ((mask & LEFT) == 0 || (mask & MID) == 0 || (mask & RIGHT) == 0) ans += 1;
        }

        return (int)ans;
    }
};