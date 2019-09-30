using System;

namespace Atcoder
{
    class Program
    {
        public static void Main(string[] arg)
        {
            Solve();
            //Console.ReadKey();
        }
        static void Solve()
        {
            string[] nk = Console.ReadLine().Split();
            int n = int.Parse(nk[0]);
            int k = int.Parse(nk[1]);

            string[] input = Console.ReadLine().Split();
            var r = new int[n];

            for (int i = 0; i < n; i++)
            {
                r[i] = int.Parse(input[i]);
            }

            Array.Sort(r);
      
            double ans = 0;
            for (int i = n - k ; i < n; i++)
            {
                ans = (ans + r[i]) / 2;
            }
            Console.WriteLine("{0:0.000000}",ans);
        }
       
    }
}