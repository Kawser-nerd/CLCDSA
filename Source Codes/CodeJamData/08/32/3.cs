using System;
using System.Collections.Generic;
using System.Text;

class Program
{
    class Solution
    {
        string s;
        long cnt = 0;

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
            s = r.ReadLine();
        }

        long [,,,] memo;
        bool [,,,] used;


        long count(int index, long sum, long term, long sign)
        {
            sum = sum % (2 * 3 * 5 * 7);
            term = term % (2 * 3 * 5 * 7);

            if (index == s.Length)
            {
                sum += term * sign;
                if (sum % 2 == 0 || sum % 3 == 0 || sum % 5 == 0 || sum % 7 == 0) return 1;
                return 0;
            }

            if (used[index, sum+2*3*5*7, term, sign+1])
                return memo[index, sum+2*3*5*7, term, sign+1];


            int d = (int)(s[index] - '0');
            long sol = 0;

            if (index > 0)
            {                
               sol = count(index + 1, sum, term * 10 + d, sign );
               sol += count(index + 1, sum + term * sign, d, -1);
            }              
            sol += count(index + 1, sum + term*sign, d, 1);

            if (sol < 0)
            {
                sol = sol;
            }
            used[index, sum+2*3*5*7, term, sign+1] = true;
            memo[index, sum+2*3*5*7, term, sign+1] = sol;
            return sol;
        }

        public string solve()
        {
            used = new bool[s.Length, 2*2*3*5*7+1, 2*3*5*7, 3];
            memo = new long[s.Length, 2*2*3*5*7+1, 2*3*5*7, 3];

            cnt = count(0,0,0,0);
            return string.Format("{0}", cnt);
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
