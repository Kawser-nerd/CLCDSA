using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc119d
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = ReadInt();
            var S = Console.ReadLine().ToCharArray();
            var ans = 1L;
            var mod = 1000000007L;
            for (char c = 'a'; c <= 'z'; c++)
            {
                ans *= (long)S.Count(x => x == c) + 1;
                ans %= mod;
            }
            ans += mod - 1;
            ans %= mod;
            Console.WriteLine(ans);
#if DEBUG
            Console.ReadKey();
#endif
        }
        private static int ReadInt() => int.Parse(Console.ReadLine());
    }
}