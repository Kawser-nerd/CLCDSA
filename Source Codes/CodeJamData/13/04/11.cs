using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace D
{
    class Program
    {
        static int N, K;
        static int[] keys;
        static int[] openkey;
        static int[][] containskeys;

        static bool[] washere;
        static int finstate;
        static Stack<int> stack;

        static bool Rec(int bitstate)
        {
            if (bitstate == finstate)
                return true;
         
            if (washere[bitstate])
                return false;
            washere[bitstate] = true;

            for (int i = 0; i < N; i++)
            {
                int key = openkey[i];
                if (keys[key] == 0)
                    continue;

                int newstate = bitstate | (1 << i);
                if (washere[newstate])
                    continue;

                keys[key]--;
                for (int j = 0; j <= 200; j++)
                    keys[j] += containskeys[i][j];

                if (Rec(newstate))
                {
                    stack.Push(i + 1);
                    return true;
                }

                keys[key]++;
                for (int j = 0; j <= 200; j++)
                    keys[j] -= containskeys[i][j];
            }

            return false;
        }

        static List<int> Solve()
        {
            if (Rec(0))
                return stack.ToList();
            return null;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                K = int.Parse(line[0]);
                N = int.Parse(line[1]);

                keys = new int[201];
                openkey = new int[N];
                containskeys = new int[N][];
                for (int i = 0; i < N; i++)
                    containskeys[i] = new int[201];

                foreach (var s in Console.ReadLine().Split())
                    keys[int.Parse(s)]++;
                //keys = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

                for (int i = 0; i < N; i++)
                {
                    line = Console.ReadLine().Split();
                    openkey[i] = int.Parse(line[0]);

                    for (int j = 2; j < line.Length; j++)
                    {
                        int k = int.Parse(line[j]);
                        containskeys[i][k]++;
                    }
                }

                washere = new bool[1 << N];
                finstate = (1 << N) - 1;
                stack = new Stack<int>();

                List<int> solution = Solve();
                if(solution == null)
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", t);
                else
                {
                    Console.Write("Case #{0}:", t);
                    foreach(var x in solution)
                        Console.Write(" {0}", x);
                    Console.WriteLine();
                }
            }
        }
    }
}
