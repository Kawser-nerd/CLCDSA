using System;
using System.Collections.Generic;
using System.Text;

namespace googlequal2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(long.MaxValue);
            int T;
            T = int.Parse(Console.ReadLine());

            for (int c = 1; c <= T; c++)
            {
                int n = int.Parse(Console.ReadLine());
                List<long> x = new List<long>();
                List<long> y = new List<long>();

                string [] s = Console.ReadLine().Split(' ');
                foreach (string n0 in s)
                    x.Add(int.Parse(n0));
                s = Console.ReadLine().Split(' ');
                foreach (string n0 in s)
                    y.Add(int.Parse(n0));

                x.Sort(); y.Sort();
                long ans = 0;
                for (int i = 1; i <= n; i++)
                    ans += x[i - 1] * y[n - i];

                Console.WriteLine("Case #{0}: {1}", c, ans);

            }

        }
    }
}
