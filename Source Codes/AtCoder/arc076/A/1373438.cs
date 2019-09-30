using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ARC076
{
    public class C
    {
        private const long Mod = 1000000000 + 7;
        private long Factorial(int x)
        {
            long result = 1;
            while (x > 0)
            {
                result *= x;
                result %= Mod;
                x--;
            }
            return result;
        }
        private void Run()
        {
            var input = Console.ReadLine().Trim().Split();
            var N = int.Parse(input[0]);
            var M = int.Parse(input[1]);

            long result;
            var max = Math.Max(N, M);
            var min = Math.Min(N, M);
            if (min + 1 == max)
            {
                result = (Factorial(M) * Factorial(N) % Mod);
            }
            else if (min == max)
            {
                result = (Factorial(M) * Factorial(N) * 2 % Mod);
            }
            else { result = 0; }
            Console.WriteLine(result);
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new C().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}