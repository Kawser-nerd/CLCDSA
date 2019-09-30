#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

#define MAXN 40
#define eps 1e-09

using namespace std;

struct coor
{
   double x, y, z;
};

int t, h, w, d, sol;
int mei, mej;
bool wall[MAXN][MAXN];
coor leftline;   // = {0, -1, 1}
coor rightline;  // = {1, -1, 1};
coor topline;    // = {1,  1, 1};
coor bottomline; // = {1,  0, 1};

bool pointonline(coor a, coor b)
{
   double inner = a.x * b.x + a.y * b.y + a.z * b.z;
   if (abs(inner) < eps)
      return true;
   return false;
}

double dist(double x1, double y1, double x2, double y2)
{
   double xdist = x2 - x1;
   double ydist = y2 - y1;
   return sqrt(xdist * xdist + ydist * ydist); 
}

double dist(coor a, coor b)
{
   double x1, y1, x2, y2;
   x1 = a.x / a.z; y1 = a.y / a.z;
   x2 = b.x / b.z; y2 = b.y / b.z;
   return dist(x1, y1, x2, y2);
}

coor makecoor(double a, double b, double c)
{
   coor res;
   res.x = a; res.y = b; res.z = c;
   return res;
}

coor cross(coor a, coor b)
{
   coor res;
   res.x = a.y * b.z - a.z * b.y;
   res.y = a.z * b.x - a.x * b.z;
   res.z = a.x * b.y - a.y * b.x;
   return res;
}

int gcd(int a, int b)
{
   if (a < b)
      return gcd(b, a);
   if (b == 0)
      return a;
   return gcd(b, a % b);
}

void init()
{
   for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++)
         wall[i][j] = 0;
   sol = mei = mej = 0;
}

void read()
{
   string line;
   cin >> h >> w >> d;
   getline(cin, line);
   for (int i = 0; i < h; i++)
   {
      getline(cin, line);
      for (int j = 0; j < w; j++)
         if (line[j] == '#')
            wall[i][j] = true;
         else if (line[j] == 'X')
         {
            mei = i;
            mej = j;
         }
   }   
}

void write(int casen)
{
   cout << "Case #" << casen << ": " << sol << endl;
}

void solve()
{
   double d1, d2, s1, s2, rem, inx, iny;
   int curi, curj;
   coor line, intersect;
   bool doright, dobottom;
   
   for (int dir1 = -200; dir1 <= 200; dir1++)
      for (int dir2 = -200; dir2 <= 200; dir2++) 
      {
         if ((dir1 == 0 && abs(dir2) != 1) || (dir2 == 0 && abs(dir1) != 1) || (dir1 != 0 && dir2 != 0 && gcd(abs(dir1), abs(dir2)) != 1))
            continue;

         curi = mei; curj = mej;
         rem = (double) d;
         d1 = (double) dir1; d2 = (double) dir2;
         s1 = 0.5; s2 = 0.5;

         while (true)
         {
            if (rem < eps)
               break;
            
            doright = dobottom = true;
            line = cross(makecoor(s1, s2, 1), makecoor(s1 + d1, s2 + d2, 1));
            
            if (curi == mei && curj == mej && (s1 != 0.5 || s2 != 0.5)) // potential solution
               if (pointonline(makecoor(0.5, 0.5, 1), line))
                  if (dist(0.5, 0.5, s1, s2) < rem + eps)
                  {
                     sol++;
                     break;
                  }                 
            
            // intersect with leftline
            intersect = cross(line, leftline);
            if (abs(intersect.z) > eps) // not parallel
            {
               inx = intersect.x / intersect.z;
               iny = intersect.y / intersect.z;

               if (!(s1 == 0.5 && s2 == 0.5 && d1 > 0) && dist(inx, iny, s1, s2) > eps)
               {
                  if (s1 == 0.5 && s2 == 0.5)
                     doright = false;
                  if (dist(inx, iny, 0, 0) < eps) // bottom leftline corner
                  {
                     rem -= dist(s1, s2, inx, iny);
                     if (wall[curi + 1][curj] && wall[curi][curj - 1] && wall[curi + 1][curj - 1]) // reflect off corner
                     {
                        d1 = -d1; d2 = -d2;
                        s1 = 0; s2 = 0;
                     }
                     else if (!wall[curi + 1][curj - 1]) // pass through corner
                     {
                        curi++; curj--;
                        s1 = 1; s2 = 1;
                     }
                     else if (wall[curi + 1][curj] && !wall[curi][curj - 1]) // reflect off bottom
                     {
                        curj--;
                        d2 = -d2;
                        s1 = 1; s2 = 0;
                     }
                     else if (!wall[curi + 1][curj] && wall[curi][curj - 1]) // reflect off left
                     {
                        curi++;
                        d1 = -d1;
                        s1 = 0; s2 = 1;
                     }
                     else // else it should die
                        rem = -1000;
                     
                     continue;
                  }
                  
                  if (dist(inx, iny, 0, 1) < eps) // top leftline corner
                  {
                     rem -= dist(s1, s2, inx, iny);
                     if (wall[curi - 1][curj] && wall[curi][curj - 1] && wall[curi - 1][curj - 1])
                     {
                        d1 = -d1; d2 = -d2;
                        s1 = 0; s2 = 1;
                     }
                     else if (!wall[curi - 1][curj - 1])
                     {
                        curi--; curj--;
                        s1 = 1; s2 = 0;
                     }
                     else if (wall[curi - 1][curj] && !wall[curi][curj - 1]) // reflect off top
                     {
                        curj--;
                        d2 = -d2;
                        s1 = 1; s2 = 1;
                     }
                     else if (!wall[curi - 1][curj] && wall[curi][curj - 1]) // reflect off left
                     {
                        curi--;
                        d1 = -d1;
                        s1 = 0; s2 = 0;
                     }
                     else
                        rem = -1000;
                     continue;
                  }
                  
                  if (iny > 0 && iny < 1) // does intersect with leftline
                  {
                     rem -= dist(s1, s2, inx, iny);
                     if (wall[curi][curj - 1])
                     {
                        d1 = -d1;
                        s1 = 0; s2 = iny;
                     }
                     else
                     {
                        curj--;
                        s1 = 1; s2 = iny;
                     }
                     continue;
                  }
               }
            }
            
            
            // intersect with rightline
            intersect = cross(line, rightline);
            if (abs(intersect.z) > eps) // not parallel
            {
               inx = intersect.x / intersect.z;
               iny = intersect.y / intersect.z;

               if (doright && dist(inx, iny, s1, s2) > eps)
               {               
                  if (dist(inx, iny, 1, 0) < eps) // bottom rightline corner
                  {
                     rem -= dist(s1, s2, inx, iny);
                     if (wall[curi + 1][curj] && wall[curi][curj + 1] && wall[curi + 1][curj + 1]) // reflect off corner
                     {
                        d1 = -d1; d2 = -d2;
                        s1 = 1; s2 = 0;
                     }
                     else if (!wall[curi + 1][curj + 1]) // pass through corner
                     {
                        curi++; curj++;
                        s1 = 0; s2 = 1;
                     }
                     else if (wall[curi + 1][curj] && !wall[curi][curj + 1]) // reflect off bottom
                     {
                        curj++;
                        d2 = -d2;
                        s1 = 0; s2 = 0;
                     }
                     else if (!wall[curi + 1][curj] && wall[curi][curj + 1]) // reflect off right
                     {
                        curi++;
                        d1 = -d1;
                        s1 = 1; s2 = 1;
                     }
                     else // else it should die
                        rem = -1000;
             
                     continue;
                  }
                  
                  if (dist(inx, iny, 1, 1) < eps) // top rightline corner
                  {
                     rem -= dist(s1, s2, inx, iny);
                     if (wall[curi - 1][curj] && wall[curi][curj + 1] && wall[curi - 1][curj + 1])
                     {
                        d1 = -d1; d2 = -d2;
                        s1 = 1; s2 = 1;
                     }
                     else if (!wall[curi - 1][curj + 1])
                     {
                        curi--; curj++;
                        s1 = 0; s2 = 0;
                     }
                     else if (wall[curi - 1][curj] && !wall[curi][curj + 1]) // reflect off top
                     {
                        curj++;
                        d2 = -d2;
                        s1 = 0; s2 = 1;
                     }
                     else if (!wall[curi - 1][curj] && wall[curi][curj + 1]) // reflect off right
                     {
                        curi--;
                        d1 = -d1;
                        s1 = 1; s2 = 0;
                     }
                     else
                        rem = -1000;
                     continue;
                  }
                  
                  if (iny > 0 && iny < 1) // does intersect with rightline
                  {
                     rem -= dist(s1, s2, inx, iny);
                     if (wall[curi][curj + 1])
                     {
                        d1 = -d1;
                        s1 = 1; s2 = iny;
                     }
                     else
                     {
                        curj++;
                        s1 = 0; s2 = iny;
                     }
                     continue;
                  }
               }
            }
            
            
            // intersect with topline
            intersect = cross(line, topline);
            if (abs(intersect.z) > eps) // not parallel
            {
               inx = intersect.x / intersect.z;
               iny = intersect.y / intersect.z;

               if (!(s1 == 0.5 && s2 == 0.5 && d2 < 0) && dist(inx, iny, s1, s2) > eps)
               {          
                  if (s1 == 0.5 && s2 == 0.5)
                     dobottom = false;
                  if (inx > 0 && inx < 1) // does intersect with topline
                  {
                     rem -= dist(s1, s2, inx, iny);
                     if (wall[curi - 1][curj])
                     {
                        d2 = -d2;
                        s1 = inx; s2 = 1;
                     }
                     else
                     {
                        curi--;
                        s1 = inx; s2 = 0;
                     }
                     continue;
                  }
               }
            }
            
            // intersect with bottomline
            intersect = cross(line, bottomline);
            if (abs(intersect.z) > eps) // not parallel
            {
               inx = intersect.x / intersect.z;
               iny = intersect.y / intersect.z;

               if (dobottom && dist(inx, iny, s1, s2) > eps)
               {               
                  if (inx > 0 && inx < 1) // does intersect with bottomline
                  {
                     rem -= dist(s1, s2, inx, iny);
                     if (wall[curi + 1][curj])
                     {
                        d2 = -d2;
                        s1 = inx; s2 = 0;
                     }
                     else
                     {
                        curi++;
                        s1 = inx; s2 = 1;
                     }
                     continue;
                  }
               }
            }
            
            
         }
      }  
}

int main()
{
   leftline = cross(makecoor(0, 0, 1), makecoor(0, 1, 1));
   rightline = cross(makecoor(1, 0, 1), makecoor(1, 1, 1));
   topline = cross(makecoor(0, 1, 1), makecoor(1, 1, 1));
   bottomline = cross(makecoor(0, 0, 1), makecoor(1, 0, 1));
   
   cin >> t;
   for (int casen = 0; casen < t; casen++)
   {
      init();
      read();
      solve();
      write(casen + 1);
   }
   return 0;
}
