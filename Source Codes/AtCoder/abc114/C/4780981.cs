using System;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static long N;

        static void Main(string[] args)
        {
            N = int.Parse(Console.ReadLine());

            Console.WriteLine(Dfs("0"));
        }

        static long Dfs(string s)
        {
            if (long.Parse(s) > N) return 0;

            bool is357 = true;
            foreach (var c357 in "357")
            {
                if (!s.Contains(c357))
                {
                    is357 = false;
                    break;
                }
            }

            var ret = is357 ? 1L : 0L;

            foreach (var item in "357")
            {
                ret += Dfs(s + item);
            }

            return ret;
        }
    }
}