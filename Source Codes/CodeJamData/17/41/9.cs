using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class A
{
    public static int P;

    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);

            string[] ps = Console.ReadLine().Split();
            int N = int.Parse(ps[0]);
            P = int.Parse(ps[1]);

            int[] counts = new int[4];
            ps = Console.ReadLine().Split();
            for (int i = 0; i < N; i++)
                counts[int.Parse(ps[i]) % P]++;

            int ans = counts[0];

            done = new bool[counts[1] + 1, counts[2] + 1, counts[3] + 1, P + 1];
            mem = new int[counts[1] + 1, counts[2] + 1, counts[3] + 1, P + 1];
            ans += rec(counts[1], counts[2], counts[3], 0);

            Console.WriteLine("Case #" + CASE + ": " + ans);
        }
    }

    public static bool[,,,] done;
    public static int[,,,] mem;
    public static int rec(int n1, int n2, int n3, int p)
    {
        int ans = 0;

        if (done[n1, n2, n3, p]) return mem[n1, n2, n3, p];

        if (n1 > 0)
            ans = Math.Max(ans, rec(n1 - 1, n2, n3, (p + 1) % P) + (p == 0 ? 1 : 0));
        if (n2 > 0)
            ans = Math.Max(ans, rec(n1, n2 - 1, n3, (p + 2) % P) + (p == 0 ? 1 : 0));
        if (n3 > 0)
            ans = Math.Max(ans, rec(n1, n2, n3 - 1, (p + 3) % P) + (p == 0 ? 1 : 0));

        done[n1, n2, n3, p] = true;
        mem[n1, n2, n3, p] = ans;
        return ans;
    }
}
