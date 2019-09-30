using System;
using System.Collections.Generic;

namespace _20190316
{
    class Program
    {
        const int mod = 1000000007;
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var str = Console.ReadLine().Trim();
            var d = new Dictionary<char, int>();
            for (int i = 0; i < n; i++)
            {
                if (d.ContainsKey(str[i])) { d[str[i]]++; }
                else { d[str[i]] = 1; }
            }
            var result = 1L;
            foreach (var item in d)
            {
                result *= item.Value + 1;
                result %= mod;
            }
            Console.WriteLine(result - 1);
        }
    }
}