using System;
using System.Collections.Generic;
using System.Text;

public class Program
{
    static int solve(int n, int[] queries)
    {
        int result = 0;
        int now = 0;
        for (;;)
        {
            int best = 0;

            for (int choice = 0; choice < n; ++choice)
            {
                int index = Array.IndexOf<int>(queries, choice, now);
                if (index < 0)
                    return result;

                best = Math.Max(best, index);
            }
            now = best;
            ++result;
        }
    }

    static void Main()
    {
        int n = Int32.Parse(Console.ReadLine());

        for (int i = 0; i < n; ++i)
        {
            int S = Int32.Parse(Console.ReadLine());
            string[] engines = new string[S];
            for (int j = 0; j < S; ++j)
                engines[j] = Console.ReadLine();

            int Q = Int32.Parse(Console.ReadLine());
            int[] queries = new int[Q];
            for (int j = 0; j < Q; ++j)
                queries[j] = Array.IndexOf<string>(engines, Console.ReadLine());

            int result = solve(S, queries);
            Console.WriteLine("Case #{0}: {1}", i+1, result);
        }
    }
}
