using System;
using System.Collections.Generic;
using System.Text;

class Program
{
    class Solution
    {
        int p, k, l;
        int[] f;

        int[] readint(System.IO.TextReader r)
        {
            string[] x = (r.ReadLine().Trim().Split(' '));
            int[] y = new int[x.Length];

            for (int i = 0; i < y.Length; i++)
                y[i] = int.Parse(x[i]);
            return y;
        }


        public void readcase(System.IO.TextReader r)        
        {
            int[] v = readint(r);
            p = v[0];
            k = v[1];
            l = v[2];

            f = readint(r);          
        }

        public string solve()
        {
            Array.Sort(f);
            Array.Reverse(f);
            int index = 0;

            long total = 0;

            for (int j = 1; j <= p; j++)
                for (int i = 0; i < k; i++)
                
                {
                    if (index >= l) break;
                    total += f[index++] * j;
                }

            return string.Format("{0}", total);
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
