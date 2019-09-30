using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class C
{
    static void Main()
    {
        int T = ReadInt();
        for (int t = 1; t <= T; t++)
        {
            int N = ReadInt();
            int[] xs = ReadInts();
            int[] hs = new int[N];
            for (int i = 0; i < N; i++)
                hs[i] = 1000000;
            bool impossible = false;
            for (int i = 0; i < N - 1 && !impossible; i++)
            {
                int s = hs[i];
                int e = hs[xs[i] - 1];
                int l = xs[i] - 1 - i;
                for (int j = i + 1; j < N && !impossible; j++)
                {
                    if (j == xs[i] - 1) continue;
                    if (j < xs[i] - 1 && xs[j] > xs[i]) impossible = true;
                    int c = s + (e - s) * (j - i) / l - (j > xs[i] - 1 ? 1 : xs[i] - j);
                    hs[j] = Math.Min(hs[j], c);
                }
            }
            if (impossible)
            {
                Console.WriteLine("Case #{0}: Impossible", t);
            }
            else
            {
                Console.Write("Case #{0}:", t);
                for (int i = 0; i < N; i++)
                {
                    Console.Write(" {0}", hs[i]);
                }
                Console.WriteLine();
            }
        }
    }

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }
}
