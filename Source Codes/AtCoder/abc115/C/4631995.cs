using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoderABC115
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            long N = long.Parse(s[0]);
            int K = int.Parse(s[1]);
            List<long> h = new List<long>();
            for (int i = 0; i < N; i++) { h.Add(long.Parse(Console.ReadLine())); }
            h = h.OrderByDescending(x => x).ToList();
            List<long> diffh = new List<long>();
            for (int i = 0; i < N - K + 1; i++) { diffh.Add(h[i] - h[i + K - 1]); }
            diffh = diffh.OrderBy(x => x).ToList();
            Console.WriteLine(diffh[0]);
        }
    }
}