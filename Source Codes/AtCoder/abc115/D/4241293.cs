using System;

namespace question4
{
    class Program2
    {
        static void Main(string[] args)
        {
            var p = new Program2();
            p.Run();
        }

        private long[] ai;
        private long[] pi;

        void Run()
        {
            var line = Console.ReadLine();
            var n = int.Parse(line.Split(' ')[0]);
            var x = long.Parse(line.Split(' ')[1]);

            ai = new long[n + 1];
            pi = new long[n + 1];

            ai[0] = 1;
            pi[0] = 1;
            for (int i = 1; i <= n; i++)
            {
                ai[i] = ai[i - 1] * 2 + 3;
                pi[i] = pi[i - 1] * 2 + 1;
            }

            var ans = this.Func(n, x);

            Console.WriteLine(ans);
        }

        long Func(int n, long x)
        {
            if( n ==0){
                return x == 1 ? 1 : 0;
            }

            if (x <= ai[n - 1] + 1)
            {
                return this.Func(n - 1, x - 1);
            }
            else if (x == ai[n - 1] + 2)
            {
                return pi[n - 1] + 1;
            }
            else if (x <= ai[n - 1] * 2 + 2)
            {
                return pi[n - 1] + 1 + this.Func(n - 1, x - (ai[n - 1] + 2));
            }
            else
            {
                return pi[n];
            }
        }
    }
}