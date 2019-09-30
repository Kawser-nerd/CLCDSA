using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static int CountChar(string s, char c)
        {
            return s.Length - s.Replace(c.ToString(), "").Length;
        }
        public static void Main(string[] args)
        {
            string S = Console.ReadLine();
            int N = S.Length;
            int num0 = CountChar(S, '0');
            int num1 = N - num0;
            Console.WriteLine((num0 > num1)? num1 * 2: num0 * 2);
        }
    }
}