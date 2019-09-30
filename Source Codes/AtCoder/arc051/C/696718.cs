using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ARC051
{
    public class C
    {
        private const long Mod = 1000000007;
        private void Run()
        {
            var input = Console.ReadLine().Trim().Split();
            var N = int.Parse(input[0]);
            var A = long.Parse(input[1]);
            var B = long.Parse(input[2]);
            var a = Console.ReadLine().Trim().Split().Select(long.Parse).OrderBy(x => x).ToArray();

            if (A >= 2)
            {
                while (B > 0)
                {
                    var min = a[0];
                    int index = Array.FindIndex(a, x => x > a[0] * A);
                    if (index < 0) { break; }

                    for (int i = 0; i < index; i++)
                    {
                        a[i] *= A;
                        if (--B == 0) { break; }
                    }
                    Array.Sort(a);
                }
                Array.Sort(a);
                if (B > 0)
                {
                    int index = (int)(B % a.Length);

                    int power = (int)(B / a.Length);
                    for (int i = 0; i < a.Length; i++)
                    {
                        a[i] *= ModPow(A, power + (i < index ? 1 : 0), Mod);
                        a[i] %= Mod;
                    }

                    var arr = new long[a.Length];
                    Array.Copy(a, index, arr, 0, a.Length - index);
                    if (index != a.Length)
                    {
                        Array.Copy(a, 0, arr, a.Length - index, index);
                    }
                    a = arr;
                }
            }
            Console.WriteLine(string.Join(Environment.NewLine, a.Select(x => x % Mod)));
        }
        public static long ModPow(long x, long n, long mod)
        {
            long res = 1;
            while (n > 0)
            {
                if ((n & 1) != 0) { res = (res * x) % mod; }
                x = (x * x) % mod;
                n >>= 1;
            }
            return res;
        }

        private static void Main()
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