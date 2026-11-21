class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0;
        //Three nested loops to compare all the points in the array.
        for(int i = 0; i < points.size(); i++) {
            for(int j = 0; j < points.size(); j++) {
                for(int k = 0; k < points.size(); k++) {
                    //skip comparisons that include several times the same point.
                    if(i != j && i != k && k != j) {
                        //declaring the three points coordinates.
                        int ax = points[i][0];
                        int ay = points[i][1];
                        int bx = points[j][0];
                        int by = points[j][1];
                        int cx = points[k][0];
                        int cy = points[k][1];

                        //declaring and initializing two vectors.
                        int vec1x = bx - ax;
                        int vec1y = by - ay;
                        int vec2x = cx - ax;
                        int vec2y = cy - ay;
                        //declaring a variable to store the current result.
                        double current = 0.5 * abs(vec1x * vec2y - vec2x * vec1y);
                        //updating result if we found a bigger area.
                        if(current > result) {
                            result = current;
                        }
                    }
                }
            }
        }
        //return result after all the comparisons.
        return result;
    }
};