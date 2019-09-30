namespace Rope
{
    using System;
    using System.Collections.Generic;

    public class Load
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            int c;

            Int64 l, p, n;

            int r;

            for (int i = 0; i < t; i++)
            {
                string[] testCase = Console.ReadLine().Split(' ');
                l = Int64.Parse(testCase[0]);
                p = Int64.Parse(testCase[1]);
                c = int.Parse(testCase[2]);

                n = 0;
                r = 0;

                while (l * c < p)
                {
                    l *= c;
                    n++;
                }

                while (n > 0)
                {
                    n = (Int64)Math.Floor((double)n / 2);
                    r++;
                }

                Console.WriteLine(String.Format("Case #{0}: {1}", i + 1, r));
            }
        }
    }
}


