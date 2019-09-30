using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.ARC076
{
    class Reconciled
    {
        public static void Main()
        {
            var nm = ReadLine().Trim().Split(' ').Select(_ => int.Parse(_)).ToArray();
            var n = nm[0]; var m = nm[1];
            long mod = 1000000007;
            if (n == m) {
                WriteLine((Factorial(n, mod) * Factorial(m, mod) * 2) % mod);
            }
            else if (n == m - 1 || n == m + 1) {
                WriteLine((Factorial(n, mod) * Factorial(m, mod)) % mod);
            }
            else {
                WriteLine(0);
            }
        }
        static long Factorial(int n, long Mod = int.MaxValue)
        {
            long res = 1;
            for (var i = 1; i <= n; ++i)
                res = res * i % Mod;
            return res;
        }
    }
}