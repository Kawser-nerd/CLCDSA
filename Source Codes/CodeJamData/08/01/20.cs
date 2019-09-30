using System;

public class universe
{
    public static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());

        for (int cs = 1; cs <= N; cs++)
        {
            int S = int.Parse(Console.ReadLine());
            string[] engines = new string[S];
            for (int i = 0; i < S; i++)
                engines[i] = Console.ReadLine();

            int Q = int.Parse(Console.ReadLine());
            string[] queries = new string[Q];
            for (int i = 0; i < Q; i++)
                queries[i] = Console.ReadLine();

            int[,] next = new int[Q, S];
            for (int i = 0; i < S; i++)
            {
                int nextj = Q;
                for (int j = Q - 1; j >= 0; j--)
                {
                    if (queries[j] == engines[i])
                        nextj = j;
                    next[j, i] = nextj;
                }
            }

            int ans = -1;
            int act = 0;
            while (act < Q)
            {
                int besti = 0;
                for (int i = 0; i < S; i++)
                    if (next[act, i] > next[act, besti])
                        besti = i;
                act = next[act, besti];
                ans++;
            }
            if (ans == -1) ans = 0;
            Console.WriteLine("Case #" + cs + ": " + ans);
        }
    }
}