using System;
using System.Collections.Generic;
using System.Text;

public class Program
{
    static string solveSmall(int S, int[][] customers)
    {
        int best = int.MaxValue;
        int bestMask = -1;
        for (int i = 0; i < (1 << S); ++i)
        {
            int maltedCount = 0;
            bool[] sat = new bool[customers.Length];
            int satcount = 0;
            
            for (int j = 0; j < S; ++j)
            {
                

                bool malted = (i & (1 << j)) != 0;
                int f = malted ? -(j+1) : j+1;
                if (malted)
                    ++maltedCount;


                for (int c = 0; c < customers.Length; ++c)
                {
                    if (sat[c])
                        continue;
                    if (Array.IndexOf<int>(customers[c], f) >= 0)
                    {
                        sat[c] = true;
                        ++satcount;
                    }
                }
            }

            if (satcount < customers.Length)
                continue;

            if (maltedCount < best)
            {
                best = maltedCount;
                bestMask = i;
            }
        }

        if (bestMask < 0)
            return "IMPOSSIBLE";

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < S; ++i)
        {
            if (i > 0)
                result.Append(" ");

            if ((bestMask & (1 << i)) != 0)
                result.Append("1");
            else
                result.Append("0");
        }

        return result.ToString();
    }

    static void Main()
    {
        int n = Int32.Parse(Console.ReadLine());

        for (int i = 0; i < n; ++i)
        {
            int S = Int32.Parse(Console.ReadLine());
            int M = Int32.Parse(Console.ReadLine());
            int[][] customers = new int[M][];

            for (int k = 0; k < M; ++k)
            {
                customers[k] = new int[k];
                string[] t = Console.ReadLine().Split(' ');
                int u = Int32.Parse(t[0]);
                customers[k] = new int[u];
                for (int q = 0; q < u; ++q)
                {
                    customers[k][q] = Int32.Parse(t[1 + q * 2]);
                    if (t[2 + q * 2] == "1")
                        customers[k][q] *= -1;
                }
            }

            var result = solveSmall(S, customers);

            Console.WriteLine("Case #{0}: {1}", i+1, result);
        }
    }
}
