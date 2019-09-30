using System;
using System.Linq;
namespace AGC010A
{
    class Program
    {
        static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            int[,] ab = new int[n, 2];
            for (int i = 0; i < n; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                ab[i, 0] = int.Parse(s[0]);
                ab[i, 1] = int.Parse(s[1]);
            }
            long ans = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if ((ab[i, 0] + ans) % ab[i, 1] == 0)
                    continue;
                ans += (ab[i, 1] - (ab[i, 0] + ans) % ab[i, 1]);
            }
            Console.WriteLine(ans);
        }
    }
}