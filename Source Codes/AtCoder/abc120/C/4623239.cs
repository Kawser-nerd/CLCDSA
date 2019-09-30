using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            string S = Console.ReadLine();
            int N = S.Length;
            int num0 = S.Count(s => s == '0');
            int num1 = N - num0;
            Console.WriteLine((num0 > num1)? num1 * 2: num0 * 2);
        }
    }
}