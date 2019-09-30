using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj14r1b
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\A-Large.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\A-Large.out");
            for (int a = 0; a < t; a++)
            {
                int n = int.Parse(lines[idx++]);
                string[] words = new string[n];
                for (int i = 0; i < n; i++)
                {
                    words[i] = lines[idx++];
                }

                List<char> order = new List<char>();
                char cur = '*';
                foreach (char c in words[0])
                {
                    if (c != cur)
                    {
                        cur = c;
                        order.Add(c);
                    }
                }
                int[][] numbers = new int[order.Count][];
                for (int j = 0; j < order.Count; j++)
                {
                    numbers[j] = new int[n];
                }
                bool valid = true;
                for (int i = 0; i < n; i++)
                {
                    int wi = 0;
                    for (int j = 0; j < order.Count; j++)
                    {
                        int cnt = 0;
                        while (wi < words[i].Length && words[i][wi] == order[j])
                        {
                            cnt++;
                            wi++;
                        }
                        if (cnt == 0)
                        {
                            valid = false;
                        }
                        numbers[j][i] = cnt;
                    }
                    if (wi < words[i].Length)
                    {
                        valid = false;
                    }
                }
                int ans = 0;
                for (int j = 0; j < order.Count; j++)
                {
                    ans += calc(numbers[j]);
                }
                if (!valid)
                {
                    tw.WriteLine("Case #{0}: Fegla Won", a + 1);
                }
                else
                {
                    tw.WriteLine("Case #{0}: {1}", a + 1, ans);
                }
            }
            tw.Close();
        }

        private static int calc(int[] p)
        {
            int minSum = int.MaxValue;
            for (int i = 1; i <= 100; i++)
            {
                int curSum = 0;
                for (int j = 0; j < p.Length; j++)
                {
                    curSum += Math.Abs(p[j] - i);
                }
                if (curSum < minSum)
                {
                    minSum = curSum;
                }
            }
            return minSum;
        }
    }
}
