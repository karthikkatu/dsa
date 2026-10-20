class Solution {
public:
    int maxDistance(string moves) {
        int vert = 0, hori = 0, free = 0;

        for (auto &c: moves) {
            vert += (c == 'U');
            vert -= (c == 'D');
            hori += (c == 'R');
            hori -= (c == 'L');
            free += (c == '_');
        }
        return abs(vert) + abs(hori) + free;
    }
};