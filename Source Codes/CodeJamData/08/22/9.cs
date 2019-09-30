using System;
using System.Collections;

public class numbersets
{
    public static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        for (int cs = 1; cs <= N; cs++)
        {
            string[] parts = Console.ReadLine().Split();
            A = int.Parse(parts[0]);
            B = int.Parse(parts[1]);
            int P = int.Parse(parts[2]);
            conn = new bool[B + 1, B + 1];
            ArrayList[] factors = new ArrayList[B + 1];
            for (int i = A; i <= B; i++)
            {
                factors[i] = new ArrayList();
                int x = i;
                int j = 2;
                while (x > 1)
                {
                    if (x % j != 0)
                    {
                        j++;
                        continue;
                    }
                    if (j >= P)
                        factors[i].Add(j);
                    while (x > 1 && ((x % j) == 0)) x /= j;
                    j++;
                }
            }
            for (int i = A; i <= B; i++)
            {
                for (int j = i + 1; j <= B; j++)
                {
                    bool ok = false;
                    for (int k = 0; !ok && k < factors[i].Count; k++)
                        if (factors[j].Contains(factors[i][k]))
                            ok = true;
                    if (ok)
                    {
                        conn[i, j] = true;
                        conn[j, i] = true;
                    }
                }
            }
            done = new bool[B + 1];
            int ans = 0;
            for (int i = A; i <= B; i++)
                if (rec(i))
                    ans++;
            Console.WriteLine("Case #" + cs + ": " + ans);
        }
    }
    static int A, B;
    static bool[,] conn;
    static bool[] done;

    static bool rec(int i)
    {
        if (done[i]) return false;
        done[i] = true;
        for (int j = A; j <= B; j++)
        {
            if (conn[i, j])
                rec(j);
        }
        return true;
    }
}