using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014sharp
{
    class R1CB
    {
        static int ways;

        static bool valid(string train)
        {
            bool[] check = new bool[26];
            char prev = '?';
            foreach (var let in train)
            {
                if (let == prev) continue;
                int idx = let - 'a';
                if (check[idx]) return false;
                check[idx] = true;
                prev = let;
            }
            return true;
        }

        static void perm(string[] cars, int n)
        {
            var len = cars.Length;
            if (n == len)
            {
                var train = string.Join("", cars);
                if (valid(train)) ways = (ways + 1) % 1000000007;
                return;
            }

            for (int i = n; i < len; i++)
            {
                var temp = cars[n];
                cars[n] = cars[i];
                cars[i] = temp;
                perm(cars, n + 1);
                temp = cars[n];
                cars[n] = cars[i];
                cars[i] = temp;
            }
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int N = int.Parse(Console.ReadLine());
                var cars = Console.ReadLine().Split();
                ways = 0;
                perm(cars, 0);
                Console.WriteLine("Case #{0}: {1}", t, ways);
            }
        }
    }
}
