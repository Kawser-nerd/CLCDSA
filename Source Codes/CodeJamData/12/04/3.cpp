#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cstring>

using namespace std;

const int MAX_SIZE = 65;

int grid[MAX_SIZE][MAX_SIZE];
int inputWidth, inputHeight;
int xOrig, yOrig;
int width, height;

struct Point {
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator<(const Point& p) const {
        return x * x + y * y < p.x * p.x + p.y * p.y;
    }
    int x, y;
};

void readGrid() {
    for (int y = 0; y < inputHeight; y++) {
        for (int x = 0; x < inputWidth; x++) {
            char c;
            scanf(" %c", &c);
            grid[x * 2][y * 2] = grid[x * 2 + 1][y * 2] = grid[x * 2][y * 2 + 1] = grid[x * 2 + 1][y * 2 + 1] = c == '#';
            if (c == 'X') {
                xOrig = x * 2 + 1;
                yOrig = y * 2 + 1;
            }
        }
    }
    width = inputWidth * 2;
    height = inputHeight * 2;
}

int computeGCD(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int computeSign(int x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int main() {
    int nCases, maxDist;
    set<pair<int, int> > skipPoints;

    scanf("%d", &nCases);
    for (int iCase = 1; iCase <= nCases; iCase++) {
        scanf("%d%d%d", &inputHeight, &inputWidth, &maxDist);
        readGrid();
        
        vector<Point> points;
        int nSolutions = 0;
        
        for (int dx = -maxDist; dx <= maxDist; dx++) {
            for (int dy = -maxDist; dy <= maxDist; dy++) {
                int sqrDist = dx * dx + dy * dy;
                if (sqrDist > 0 && sqrDist <= maxDist * maxDist) {
                    points.push_back(Point(dx, dy));
                }
            }
        }
        sort(points.begin(), points.end());
        skipPoints.clear();

        for (int i = points.size() - 1; i >= 0; i--) {
            int dx = points[i].x, dy = points[i].y;
            if (skipPoints.find(make_pair(dx, dy)) != skipPoints.end()) continue;

            int gcd = computeGCD(abs(dx), abs(dy));
            
            for (int j = 1; j < gcd; j++) {
                skipPoints.insert(make_pair(dx / gcd * j, dy / gcd * j));
            }
            
            int xMult = dy == 0 ? 1 : abs(dy) / gcd;
            int yMult = dx == 0 ? 1 : abs(dx) / gcd;

            int sxOrig = xOrig * xMult, syOrig = yOrig * yMult;
            int sxDir = computeSign(dx), syDir = computeSign(dy);
            int sx = sxOrig, sy = syOrig;
            int iMax = 2 * max(abs(dx) * xMult, abs(dy) * yMult);

            bool isSolution = false;

            for (int i = 0; i < iMax; i++) {
                sx += sxDir;
                sy += syDir;

                if (sx == sxOrig && sy == syOrig) {
                    isSolution = true;
                    break;
                }

                bool bumpX = sx % (2 * xMult) == 0;
                bool bumpY = sy % (2 * yMult) == 0;
                int x = sx / xMult;
                int y = sy / yMult;

                int oldX = (sxDir == 1 && bumpX) ? (x - 1) : x;
                int newX = (sxDir == -1 && bumpX) ? (x - 1) : x;
                int oldY = (syDir == 1 && bumpY) ? (y - 1) : y;
                int newY = (syDir == -1 && bumpY) ? (y - 1) : y;
                assert(oldX >= 0 && oldX < width && oldY >= 0 && oldY < height);
                if (newX < 0 || newX >= width || oldY < 0 || oldY >= height) break;

                if (grid[newX][newY]) {
                    if (bumpX && !bumpY) {
                        assert(sxDir != 0);
                        assert(grid[oldX][y] == 0);
                        sxDir = -sxDir;
                    } else if (bumpY && !bumpX) {
                        assert(syDir != 0);
                        assert(grid[x][oldY] == 0);
                        syDir = -syDir;
                    } else if (bumpX && bumpY) {
                        if (grid[newX][oldY] && grid[oldX][newY]) {
                            sxDir = -sxDir;
                            syDir = -syDir;
                        } else if (grid[newX][oldY]) {
                            sxDir = -sxDir;
                        } else if (grid[oldX][newY]) {
                            syDir = -syDir;
                        } else {
                            break;
                        }
                    }
                }
            }
            nSolutions += isSolution;
        }
        
        printf("Case #%i: %i\n", iCase, nSolutions);
    }
    return 0;
}
