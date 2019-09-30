using System;
using System.Linq;
namespace AGC011A
{
    class Passenger
    {
        public int m;
        public int M;
        public Passenger(int t, int k) { m = t; M = t + k; }
        public bool Judge(int t) { return m <= t && t <= M; }
    }
    class Program
    {
        static void Main()
        {
            string[] s = Console.ReadLine().Split(' ');
            int n, c, k;
            n = int.Parse(s[0]);
            c = int.Parse(s[1]);
            k = int.Parse(s[2]);
            int[] t = new int[n];
            for (int i = 0; i < n; i++)
                t[i] = int.Parse(Console.ReadLine());
            Array.Sort(t);
            Passenger[] ps = new Passenger[n];
            for (int i = 0; i < n; i++)
                ps[i] = new Passenger(t[i], k);
            int f = 0;
            int ans = 1;
            bool fl = false;
            for (; ; )
            {
                if (f == n)
                {
                    Console.WriteLine(ans - 1);
                    Environment.Exit(0);
                }
                for (int i = 0; i < c; i++)
                {
                    try
                    {
                        if (!ps[f + i].Judge(ps[f].M))
                        {
                            f += i;
                            fl = true;
                            break;
                        }
                    }
                    catch (IndexOutOfRangeException) { Console.WriteLine(ans); Environment.Exit(0); }
                }
                if (fl)
                {
                    fl = false;
                    ans++;
                    continue;
                }
                f += c;
                ans++;
            }
        }
    }
}