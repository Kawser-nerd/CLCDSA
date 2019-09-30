using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class B
{
    static void Main()
    {
        int T = ReadInt();
        for (int t = 1; t <= T; t++)
        {
            int[] tmp = ReadInts();
            int N = tmp[0], W = tmp[1], L = tmp[2];
            int[] rs = ReadInts(), idxs = Enumerable.Range(1, N).ToArray();
            Array.Sort(rs, idxs);
            Tuple<int, int>[] locs = new Tuple<int, int>[N];
            locs[0] = new Tuple<int, int>(0, 0);
            bool firstRow = true;
            for (int i = 1; i < N; i++)
            {
                int next = locs[i-1].Item1 + rs[i-1] + rs[i];
                if (next <= W)
                    locs[i] = new Tuple<int, int>(next, firstRow ? locs[i - 1].Item2 : locs[i - 1].Item2 - rs[i - 1] + rs[i]);
                else
                {
                    firstRow = false;
                    locs[i] = new Tuple<int, int>(0, locs[i - 1].Item2 + rs[i - 1] + rs[i]);
                }
            }
            if (locs[N - 1].Item2 > L) Console.Error.WriteLine("FAIL");
            Array.Sort(idxs, locs);
            Console.Write("Case #{0}:", t);
            foreach (Tuple<int, int> loc in locs)
            {
                Console.Write(" {0} {1}", loc.Item1, loc.Item2);
            }
            Console.WriteLine();
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
