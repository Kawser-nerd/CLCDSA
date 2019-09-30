using System;

public class cheating
{
    public static void Main(string[] args)
    {
        int CASES = int.Parse(Console.ReadLine());

        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            string[] parts = Console.ReadLine().Split();
            int M = int.Parse(parts[0]);
            int N = int.Parse(parts[1]);

            bool[,] isPossible = new bool[M, N];
            for (int i = 0; i < M; i++)
            {
                string line = Console.ReadLine();
                for (int j = 0; j < N; j++)
                {
                    isPossible[i, j] = line[j] == '.';
                }
            }
            int[,] maxNum = new int[M + 1, 1 << N];
            for (int i = 1; i <= M; i++)
            {
                for (int j = 0; j < (1 << N); j++)
                {
                    bool possible = true;
                    int bitcount = 0;
                    for (int k = 0; k < N; k++)
                    {
                        if ((j & (1 << k)) > 0)
                        {
                            if (!isPossible[i - 1, k]) possible = false;
                            bitcount++;
                            if (k < N - 1 && (j & (1 << (k + 1))) > 0)
                                possible = false;
                        }
                    }
                    if (!possible) continue;
                    for (int k = 0; k < (1 << N); k++)
                    {
                        bool domatch = true;
                        for (int m = 0; m < N; m++)
                        {
                            if ((j & (1 << m)) > 0)
                            {
                                if (m > 0)
                                {
                                    if ((k & (1 << (m - 1))) > 0)
                                        domatch = false;
                                }
                                if (m < N - 1)
                                {
                                    if ((k & (1 << (m + 1))) > 0)
                                        domatch = false;
                                }
                            }
                        }
                        if (domatch)
                        {
                            maxNum[i, j] = Math.Max(maxNum[i, j], bitcount + maxNum[i - 1, k]);
                        }
                    }
                }
            }
            int totalMax = 0;
            for (int i = 0; i < (1 << N); i++)
                totalMax = Math.Max(totalMax, maxNum[M, i]);
            Console.WriteLine("Case #" + CASE + ": " + totalMax);
        }
    }
}