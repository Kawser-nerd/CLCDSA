using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class A
{
    static int[] pow3 = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441 };
    public static void Main(string[] args)
    {
        done = new bool[13, 531441];
        mem = new bool[13, 531441];

        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            string[] ps = Console.ReadLine().Split();
            int N = int.Parse(ps[0]);
            int R = int.Parse(ps[1]);
            int P = int.Parse(ps[2]);
            int S = int.Parse(ps[3]);
            string ans = "IMPOSSIBLE";
            string chars = "PRS";

            for(int i = 0; i < pow3[1 << N]; i++)
            {
                if (!ok(N, i)) continue;

                int mask = i;
                int[] counts = new int[3];
                for (int j = 0; j < (1 << N); j++)
                {
                    counts[mask % 3]++;
                    mask /= 3;
                }
                if (counts[0] == P && counts[1] == R && counts[2] == S)
                {
                    char[] cur = new char[1 << N];
                    mask = i;
                    for (int j = 0; j < (1 << N); j++)
                    {
                        cur[(1 << N) - j - 1] = chars[mask % 3];
                        mask /= 3;
                    }
                    ans = new string(cur);
                    break;
                }
            }

            Console.WriteLine("Case #" + CASE + ": " + ans);
        }
    }

    static bool[,] done;
    static bool[,] mem;

    public static bool ok(int n, int mask)
    {
        if (n == 0) return true;
        if (done[n, mask]) return mem[n, mask];
        done[n, mask] = true;

        int newmask = 0;
        int tmp = mask;
        for (int i = 0; i < (1 << (n - 1)); i++)
        {
            int n1 = tmp % 3;
            tmp /= 3;
            int n2 = tmp % 3;
            tmp /= 3;
            if (n1 == n2) return mem[n, mask] = false;

            // 0 < 1, 1 < 2, 2 < 0
            newmask *= 3;
            if ((n1 + 1) % 3 == n2)
                newmask += n2;
            else
                newmask += n1;
        }

        return mem[n, mask] = ok(n - 1, newmask);
    }
}
