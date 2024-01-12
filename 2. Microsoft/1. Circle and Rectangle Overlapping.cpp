// Link : https://leetcode.com/problems/circle-and-rectangle-overlapping/description/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                double parameter=(i-xCenter)*(i-xCenter) + (j-yCenter)*(j-yCenter);
                double r=radius*radius;
                if(parameter<=r) return true;
            }
        }
        return false;
    }
};