using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC114
{
    class Program
    {
        public static List<long> GetL(long x)
        {
            if (x > 100000000) return new List<long>();
            List<long> l1 = new List<long>();
            List<long> l2 = new List<long>();
            List<long> l3 = new List<long>();
            l1.Add(10 * x + 3);
            l1 = l1.Concat(GetL(10 * x + 3)).ToList();
            l2.Add(10 * x + 5);
            l2 = l2.Concat(GetL(10 * x + 5)).ToList();
            l3.Add(10 * x + 7);
            l3 = l3.Concat(GetL(10 * x + 7)).ToList();
            return l1.Concat(l2).Concat(l3).ToList();
        }

        public static bool Judge(long x)
        {
            string s = Convert.ToString(x, 10);
            return s.Contains("7") && s.Contains("5") && s.Contains("3");
        }

        public static void Main(string[] args)
        {
            long N = long.Parse(Console.ReadLine());
            List<long> l = GetL(0).OrderBy(x => x).ToList();
            long res = 0;
            for (int i = 0; i < l.Count && l[i] <= N; i++)
            {
                if (Judge(l[i])) res++;
            }
            Console.WriteLine(res);
        }
    }
}