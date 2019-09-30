using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    class Program
    {
        static int count(string s, string pat) {
            return (s.Length - s.Replace(pat, "").Length)/pat.Length;
        }

        static List<string> pat = new List<string>() { "AA","AB","AX","AY",
                                                    "BA","BB","BX","BY",
                                                    "XA","XB","XX","XY",
                                                    "YA","YB","YX","YY"};
        static int solve(int n, string s)
        {
            if (n == 0) return s.Replace("0", "").Length;
            else {
                int min = int.MaxValue;
                foreach (var p in pat)
                {
                    int num = count(s, p) + solve(n - 1, s.Replace(p, "0"));
                    min = Math.Min(min,num);
                }
                return min;
            }

        }

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            Console.WriteLine(solve(2,s).ToString());
        }
    }
}