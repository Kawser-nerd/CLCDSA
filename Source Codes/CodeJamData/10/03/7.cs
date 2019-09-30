using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codeajm2010
{
    class ThemePark
    {
        private static long solve(long R, long k, List<long> g)
        {
            //first compute the how many group could board when g[i] is the head of queue
            List<int> NextStart = new List<int>();
            List<long> Income= new List<long>();
            long sum = g[0];
            int i = 0;
            int end = 1; //not inclusive
            if (end == g.Count) end = 0;
            while (true) {
                if (end == i) { //whole queue could board)
                    break;
                }
                if (sum + g[end] <= k) {
                    sum += g[end];
                    ++end;
                    if (end == g.Count) end = 0;
                } else {
                    break;
                }                
            }
            if (end == i) { //whole group could board
                return R * sum;
            }
            Income.Add(sum);
            NextStart.Add(end); //the start of next queue
            for (i = 1; i < g.Count; i++) {
                sum -= g[i-1];
                while (true) {
                    if (sum + g[end] <= k) {
                        sum += g[end];
                        ++end;
                        if (end == g.Count) end = 0;
                    } else {
                        break;
                    }
                }
                Income.Add(sum);
                NextStart.Add(end);
            }
            int start = 0;
            long total= 0;
            for (i = 0; i < R; i++) {
                end = NextStart[start];
                total += Income[start];
                start = end;
            }
            return total;
        }
        public static void Main(string[] args)
        {

            long cases = Convert.ToInt32(System.Console.In.ReadLine().Trim());
            for (long i = 0; i < cases; i++) {
                string s = System.Console.In.ReadLine();
                string[] v = s.Split(' ');
                long R = Convert.ToInt64(v[0].Trim());
                long k = Convert.ToInt64(v[1].Trim());
                v = System.Console.In.ReadLine().Split();
                List<long> g = new List<long>();
                foreach (var item in v) {
                    g.Add(Convert.ToInt64(item));
                }
                System.Console.Out.WriteLine(string.Format("Case #{0}: {1}", i + 1, solve(R, k, g)));
            }
        }

    }
}
