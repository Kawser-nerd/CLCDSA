using System;
using System.Collections.Generic;
using System.Text;

class Program
{
    class Solution
    {
        string s;

        int[] readint(System.IO.TextReader r)
        {
            string[] x = (r.ReadLine().Trim().Split(' '));
            int[] y = new int[x.Length];

            for (int i = 0; i < y.Length; i++)
                y[i] = int.Parse(x[i]);
            return y;
        }


        int k;
        public void readcase(System.IO.TextReader r)        
        {
            k = int.Parse(r.ReadLine());
            s = r.ReadLine();
        }

        int min;
        int[] p;
        void check()
        {
            char old = '\0';

            int cnt = 0;

            for (int i = 0; i < s.Length; i++)
            {
                int j = i % k;
                int i0 = i - j;

                char c = s[i0 + p[j]];

                if (c != old) cnt++;
                old = c;
            }

            if (cnt < min) min = cnt;
        }

        void perm(int i, int used)
        {
            if (i == k)
            {
                check();
                return;
            }

            for (int j = 0; j < k; j++)
            {
                int x = 1 << j;
                if ((used & x) != 0) continue;
                p[i] = j;
                perm(i + 1, used | x);
            }
        }
        public string solve()
        {
            min = int.MaxValue;
            p = new int[k];
            perm(0, 0);

            return string.Format("{0}", min);
        }
    }

    static void Main(string[] args)
    {
        System.IO.TextReader r = new System.IO.StreamReader("../../a.in");
        System.IO.TextWriter w = new System.IO.StreamWriter("../../a.out");
        int n = int.Parse(r.ReadLine());

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
