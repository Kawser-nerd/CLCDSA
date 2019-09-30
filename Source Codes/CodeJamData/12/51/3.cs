using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class A
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            int N = int.Parse(Console.ReadLine());
            string[] p = Console.ReadLine().Split();
            p = Console.ReadLine().Split();
            int[] P = new int[N];
            for (int i = 0; i < N; i++)
                P[i] = int.Parse(p[i]);
            bool[] done = new bool[N];
            Console.Write("Case #" + CASE + ":");
            for (int i = 0; i < N; i++)
            {
                int besti = -1;
                for (int j = 0; j < N; j++)
                {
                    if (done[j]) continue;
                    if (besti == -1 || P[j] > P[besti])
                        besti = j;
                }
                Console.Write(" {0}", besti);
                done[besti] = true;
            }
            Console.WriteLine();
        }
    }
}
