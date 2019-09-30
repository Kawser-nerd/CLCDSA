using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgrammingContest.GoogleCodeJam._2011.Round1.A
{
    class The_Killer_Word
    {
        static int[] ReadInts() { return Array.ConvertAll(Console.ReadLine().Split(' '), sss => int.Parse(sss)); }

        static string[] dic;
        static int[][] pattern;

        static int Score(int sel, List<int> index, string lst)
        {
            int res = 0;
            int hash = (1 << dic[sel].Length) - 1;
            foreach (var c in lst)
            {
                if (hash == 0 || index.Count == 1)
                    break;
                if (index.All(xx => pattern[xx][c] == 0))
                    continue;
                if (pattern[sel][c] == 0)
                {
                    //Console.WriteLine("{0} {1}: {2}", lst, dic[index[i]], s);
                    //Console.WriteLine("({0} {1} {2})", sel, lst, c);
                    res++;
                }
                index.RemoveAll(xx => pattern[xx][c] != pattern[sel][c]);
                hash &= ~pattern[sel][c];
            }
            return res;
        }

        static string Solve(string lst)
        {
            int max = -1, idx = -1;
            for (int len = 1; len <= 10; len++)
            {
                List<int> index = new List<int>();
                for (int i = 0; i < dic.Length; i++)
                    if (dic[i].Length == len)
                        index.Add(i);

                for (int i = 0; i < index.Count; i++)
                {
                    //Console.Error.WriteLine("check: {0}", i);
                    int s = Score(index[i], new List<int>(index), lst);
                    if (max < s || max == s && index[i] < idx)
                    {
                        max = s;
                        idx = index[i];
                    }
                }
            }
            return dic[idx];
        }

        static void Main()
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                var NM = ReadInts();
                int N = NM[0],
                    M = NM[1];

                dic = new string[N];
                var lst = new string[M];

                for (int i = 0; i < N; i++)
                    dic[i] = Console.ReadLine();

                for (int i = 0; i < M; i++)
                    lst[i] = Console.ReadLine();

                pattern = new int[N][];
                for (int i = 0; i < N; i++)
                {
                    pattern[i] = new int[256];
                    for (int j = 0; j < dic[i].Length; j++)
                        pattern[i][dic[i][j]] |= 1 << j;
                }

                Console.Write("Case #{0}:", t);
                for (int i = 0; i < M; i++)
                    Console.Write(" {0}", Solve(lst[i]));
                Console.WriteLine();
            }
        }
    }
}
