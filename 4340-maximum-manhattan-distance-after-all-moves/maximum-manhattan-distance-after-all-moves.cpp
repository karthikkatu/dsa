class Solution {
public:
    int distance(int x,int y) {
        return abs(x) + abs(y);
    }

    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int dc = 0;
        int dist = 0;

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

        if(x<0)x-=dc;
        else x+=dc;

        dist = max(dist,distance(x,y));
        // cout<<dist<<endl;
        // dist = max(dist,distance(x,y-dc));
        // cout<<dist<<endl;
        // dist = max(dist,distance(x+dc,y));
        // cout<<dist<<endl;
        // dist = max(dist,distance(x-dc,y));
        // cout<<dist<<endl;


        return dist;
    }
};