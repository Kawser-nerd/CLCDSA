using System;
using System.Collections.Generic;
using System.Text;

class Program
{
    class Solution
    {
        int n, m;
        long x, y, z;

        long[] v;

        

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
            int[] vec = readint(r);

            n = vec[0];
            m = vec[1];
            x = vec[2];
            y = vec[3];
            z = vec[4];

            v = new long[n];
            long[] a = new long[m];

            for (int i = 0; i < m; i++)
            {
                a[i] = int.Parse(r.ReadLine());
            }

            for (int i = 0; i < n; i++)
            {
                v[i] = a[i % m];
                a[i % m] = (((x * a[i % m])) % z + ((y * (i + 1)) % z)) % z;
            }
        }

        bool[,] used;
        long[,] memo;


        long go(int i, int min)
        {
            if (i == n) return 1;
            if (used[i, min]) return memo[i, min];

            if (i != min)
                memo[i, min] = go(i + 1, min);

            if (i == min || v[i] > v[min])
                memo[i, min] += go(i + 1, i);

            memo[i, min] = memo[i, min] % 1000000007;

            used[i, min] = true;
            return memo[i, min];            
        }

        public string solve()
        {
            used = new bool[n,n];
            memo = new long[n,n];

            
            long sol = 0;

            for (int i = 0; i < n; i++)
            {
                sol = (sol + go(i,i)) % 1000000007;               
            }



            return string.Format("{0}", sol);
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
