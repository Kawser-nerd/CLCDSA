using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Google3
{
    class Program
    {
        static string num;
        static bool IsUgly(long num)
        {
            long x = Math.Abs(num);
            return (x % 2 == 0) || (x % 3 == 0) || (x % 5 == 0) || (x % 7 == 0);
        }

        static long Get2(string num, long bef)
        {
            long ugly = 0;
            for (int i = 0; i < (num.Length - 1); i++)
            {
                ugly += Get2(num.Substring(i + 1), bef + long.Parse(num.Substring(0, i + 1)));
                ugly += Get2(num.Substring(i + 1), bef - long.Parse(num.Substring(0, i + 1)));
            }
            if (IsUgly(bef - long.Parse(num))) ugly++;
            if (IsUgly(bef + long.Parse(num))) ugly++;
            return ugly;
        }

        static long Get()
        {
            long ugly = 0;
            for (int i = 0; i < (num.Length-1); i++)
            {
                ugly +=Get2(num.Substring(i+1),long.Parse(num.Substring(0,i + 1)));
            }
            if (IsUgly(long.Parse(num))) ugly++;
            return ugly;
        }

        static void Read(string path)
        {
            System.IO.StreamReader sr = new System.IO.StreamReader(path);
            long N = long.Parse(sr.ReadLine());
            for (long i = 0; i < N; i++)
            {
                num = sr.ReadLine();
                Console.WriteLine("Case #{0}: {1}", i + 1, Get());
            }
        }
        static void Main(string[] args)
        {
            Read("input.txt");
        }
    }
}
