using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class A
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            string[] ps = Console.ReadLine().Split();
            long D = long.Parse(ps[0]);
            long N = long.Parse(ps[1]);
            long[] K = new long[N];
            long[] S = new long[N];
            double arrival = 0;
            for(int i = 0; i < N; i++)
            {
                ps = Console.ReadLine().Split();
                K[i] = long.Parse(ps[0]);
                S[i] = long.Parse(ps[1]);
                arrival = Math.Max(arrival, (double)(D - K[i]) / (double)S[i]);
            }
            Console.WriteLine("Case #" + CASE + ": " + ((double)D / arrival));
        }
    }
}
