using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Watersheds
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextWriter tw = new StreamWriter(@"D:\Downloads\output.txt"))
            using (TextReader tr = new StreamReader(@"D:\Downloads\B-large.in"))
            {
                int cases = int.Parse(tr.ReadLine());
                for (int i=1; i<=cases; ++i)
                {
                    string[] nm = tr.ReadLine().Split(' ');
                    int n = int.Parse(nm[0]);
                    int m = int.Parse(nm[1]);
                    int[,] a = new int[n, m];
                    for (int r=0; r<n; ++r)
                    {
                        string[] row = tr.ReadLine().Split(' ');
                        for (int c=0; c<m; ++c)
                        {
                            a[r, c] = int.Parse(row[c]);
                        }
                    }

                    int[,] sol = Solve(n, m, a);

                    tw.WriteLine("Case #{0}:", i);
                    StringBuilder sb = new StringBuilder(2*m + 2);
                    for (int r=0; r<n; ++r)
                    {
                        sb.Length = 0;
                        for (int c=0; c<m; ++c)
                        {
                            sb.Append((char)('a' + sol[r, c] - 1)).Append(' ');
                        }
                        sb.Length -= 1;
                        tw.WriteLine(sb);
                    }
                }
            }
        }

        private static int[,] XOD = new int[,]{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        private static int[,] Solve(int n, int m, int[,] a)
        {
            int[,] ans = new int[n, m];
            int x, y;
            int maxlabel = 0;
            List<int> xvis = new List<int>();
            List<int> yvis = new List<int>();
            while (FindFree(n, m, ans, out x, out y))
            {
                xvis.Add(x);
                yvis.Add(y);
                while (true)
                {
                    int nx, ny;
                    DecideNext(n, m, a, x, y, out nx, out ny);
                    int label = nx==-1 ? -1 : ans[nx, ny];
                    if (label == 0)
                    {
                        xvis.Add(nx);
                        yvis.Add(ny);
                        x = nx;
                        y = ny;
                    }
                    else
                    {
                        if (label == -1)
                        {
                            label = ++maxlabel;
                        }
                        for (int i = 0; i < xvis.Count; ++i)
                        {
                            ans[xvis[i], yvis[i]] = label;
                        }
                        xvis.Clear();
                        yvis.Clear();
                        break;
                    }
                }
            }
            return ans;
        }

        private static int DecideNext(int n, int m, int[,] a, int x, int y, out int nx, out int ny)
        {
            int h = a[x, y];
            int minx = -1, miny = -1;
            for (int i=0; i<4; ++i)
            {
                nx = x + XOD[i, 0];
                ny = y + XOD[i, 1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx, ny] >= h) continue;
                h = a[nx, ny];
                minx = nx;
                miny = ny;
            }
            nx = minx;
            ny = miny;
            return minx == -1 ? -1 : a[nx, ny];
        }

        private static bool FindFree(int n, int m, int[,] a, out int x, out int y)
        {
            for (x=0; x<n; ++x)
            {
                for (y=0; y<m; ++y)
                {
                    if (a[x,y]==0)
                    {
                        return true;
                    }
                }
            }
            x = y = -1;
            return false;
        }
    }
}
