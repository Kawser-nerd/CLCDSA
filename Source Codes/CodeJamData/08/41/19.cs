using System;
using System.Collections.Generic;
using System.Text;

class Program
{
    class Solution
    {       
        int[] readint(System.IO.TextReader r)
        {
            string[] x = (r.ReadLine().Trim().Split(' '));
            int[] y = new int[x.Length];

            for (int i = 0; i < y.Length; i++)
                y[i] = int.Parse(x[i]);
            return y;
        }

        int m, v;
        int[] g, c;
        bool[] interior;

        int[] minchanges(int node)
        {
            int[] answer = new int[2];
            if (!interior[node])
            {
                answer[g[node]] = 0;
                answer[1 - g[node]] = 1000000;
                return answer;
            }

            int[] a = minchanges(node * 2 + 1);
            int[] b = minchanges(node * 2 + 2);

            int x0,x1;
            // 0

            x1 = Math.Min(a[0], b[0]);
            x0 = a[0] + b[0];

            if (g[node] == 1) // and
            {
                if (c[node] == 1)                
                    x0++;                
                else
                    x0 = 1000000;

            } else           
            {
                if (c[node] == 1)
                {
                    x1++;
                }
                else
                    x1 = 1000000;
                
            }

            
            answer[0] = Math.Min(x0, x1);

            // 1 ---------------
            x1 = a[1]+ b[1];
            x0 = Math.Min(a[1], b[1]);

            if (g[node] == 1) // and
            {
                if (c[node] == 1)
                    x0++;
                else
                    x0 = 1000000;

            }
            else
            {
                if (c[node] == 1)
                {
                    x1++;
                }
                else
                    x1 = 1000000;

            }

            answer[1] = Math.Min(x0, x1);

            return answer;
        }

        public void randcase(int m)
        {
            g = new int[m];
            c = new int[m];
            interior = new bool[m];
            Random r = new Random();
            v = r.Next(2);
            for (int i = 0; i < m; i++)
            {
                g[i] = r.Next(2);
                c[i] = r.Next(2);
                if (i < (m - 1) / 2)
                    interior[i] = true;
            }
        }

        public void readcase(System.IO.TextReader r)        
        {
            int[] x = readint(r);

            m = x[0];
            v = x[1];
            g = new int[m];
            c = new int[m];
            interior = new bool[m];

            for (int i = 0;     i < (m-1)/2; i++)
            {
                interior[i] = true;
                x = readint(r);
                g[i] = x[0];
                c[i] = x[1];
            }

            for (int i = (m - 1) / 2; i < m; i++)
            {
                interior[i] = false;
                g[i] = readint(r)[0];
            }
        }

        public string solve()
        {
            int[] x = minchanges(0);
            int y = x[v];
            if (y > m) return "IMPOSSIBLE";

            return string.Format("{0}", y);
        }
    }

    static void Main(string[] args)
    {
        System.IO.TextReader r = new System.IO.StreamReader("../../a.in");
        System.IO.TextWriter w = new System.IO.StreamWriter("../../a.out");
        int n = int.Parse(r.ReadLine());
        Solution x = new Solution();
        

        
        for (int i = 0; i < n; i++)
        {
            Solution t = new Solution();
            t.readcase(r);

            string s = t.solve();
           
            w.WriteLine("Case #{0}: {1}", i + 1, s);
        }
        w.Close();
    }
}
