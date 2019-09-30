using System;
using System.Linq;

namespace arc066_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            long ret = 1;
            Array.Sort(x);
            if (n % 2 == 0)
            {
                bool ok = true;
                for (int i = 0; i < n / 2; i++)
                {
                    if (x[i * 2] != i * 2 + 1 || x[i * 2 + 1] != i * 2 + 1) ok = false;
                    ret *= 2; ret %= 1000000007;
                }
                Console.WriteLine(ok ? ret : 0);
            }
            else
            {
                bool ok = x[0] == 0;
                for (int i = 0; i < n / 2; i++)
                {
                    if (x[i * 2 + 1] != (i + 1) * 2 || x[i * 2 + 2] != (i + 1) * 2) ok = false;
                    ret *= 2; ret %= 1000000007;
                }
                Console.WriteLine(ok ? ret : 0);
            }
        }
    }
}