using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoderABC115
{
    class Program
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<int> l = new List<int>();
            for (int i = 0; i < N; i++)
            {
                l.Add(int.Parse(Console.ReadLine()));
            }
            l = l.OrderByDescending(x => x).ToList();
            int res = l[0] / 2;
            for (int i = 1; i < N; i++)
            {
                res += l[i];
            }
            Console.WriteLine(res);
        }
    }
}