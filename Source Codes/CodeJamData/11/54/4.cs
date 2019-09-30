using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace R3ProblemD
{
    class Program
    {
        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                string str = Console.ReadLine();
                List<int> pos = new List<int>();
                for (int i = 0; i < str.Length; ++i)
                {
                    if (str[i] == '?') pos.Add(i);
                }
                StringBuilder sb = new StringBuilder(str);
                for (int i = 0; i < (1 << pos.Count); ++i)
                {
                    for (int j = 0; j < pos.Count; ++j)
                    {
                        if (((i >> j) & 1) == 0) sb[pos[j]] = '0';
                        else sb[pos[j]] = '1';
                    }
                    long cur = Convert.ToInt64(sb.ToString(), 2);
                    long tmp = (long)Math.Sqrt(cur);
                    if (tmp * tmp == cur)
                    {
                        Console.WriteLine("Case #{0}: {1}", curCase + 1, sb.ToString());
                        break;
                    }
                }
            }
        }
    }
}
