using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class B
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            string[] ps = Console.ReadLine().Split();
            int N = int.Parse(ps[0]);
            int C = int.Parse(ps[1]);
            if (C != 2) throw new Exception("This is too hard for me");
            int M = int.Parse(ps[2]);

            List<int> p1 = new List<int>();
            List<int> p2 = new List<int>();

            int[] counts = new int[N + 1];
            int[] counts1 = new int[N + 1];
            int[] counts2 = new int[N + 1];
            for (int i = 0; i < M; i++)
            {
                ps = Console.ReadLine().Split();
                int pi = int.Parse(ps[0]);
                if (ps[1] == "1")
                {
                    p2.Add(pi);
                    counts2[pi]++;
                }
                else
                {
                    p1.Add(pi);
                    counts1[pi]++;
                }
                counts[pi]++;
            }
            
            int rides = Math.Max(counts[1], Math.Max(p1.Count, p2.Count));

            int highest = 2;
            for (int i = 3; i <= N; i++)
                if (counts[i] > counts[highest])
                    highest = i;

            int reassign = Math.Max(0, counts[highest] - rides);

            Console.WriteLine("Case #" + CASE + ": " + rides + " " + reassign);
        }
    }
}
