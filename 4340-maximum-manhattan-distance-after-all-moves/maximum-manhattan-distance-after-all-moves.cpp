class Solution {
public:
    double distance(int x,int y) {
        return abs(x) + abs(y);
    }

    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int dc = 0;
        double dist = 0;

        for(char c:moves) {
            if(c=='U'){
                y++;
            } else if(c=='D'){
                y--;
            } else if(c=='L'){
                x--;
            }else if(c=='R') {
                x++;
            } else {
                dc++;
            }
        }

        dist = max(dist,distance(x,y+dc));
        dist = max(dist,distance(x,y-dc));
        dist = max(dist,distance(x+dc,y));
        dist = max(dist,distance(x-dc,y));


        return dist;
    }
};