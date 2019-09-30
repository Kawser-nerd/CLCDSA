using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC114
{
    class Program
    {
        public static void Main(string[] args)
        {
            string S = Console.ReadLine();
            List<int> l = new List<int>();
            for (int i = 0; i < S.Length - 2; i++)
            {
                l.Add(Math.Abs(int.Parse(S.Substring(i, 3)) - 753));
            }
            l = l.OrderBy(x => x).ToList();
            Console.WriteLine(l[0]);
        }
    }
}