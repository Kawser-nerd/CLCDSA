using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public long MOD = 1000000007;
        public List<List<int>> countComb;
        public Dictionary<int, int> dict;

        public void Run()
        {
            N = Input.ReadInt();

            // ?????
            dict = new Dictionary<int, int>();
            for (int i = 1; i <= N; i++)
            {
                int x = i;
                int p = 2;
                while (x > 1)
                {
                    if (x % p == 0)
                    {
                        if (!dict.ContainsKey(p)) dict.Add(p, 0);
                        dict[p]++;
                        x /= p;
                    }
                    else
                    {
                        p++;
                    }
                }
            }

            // 75???????????
            countComb = new List<List<int>>();
            DFS(75, 2, new List<int>());

            long ret = 0;
            for (int i = 0; i < countComb.Count; i++)
            {
                var bf = new BruteForceBit(() => ret++, countComb[i], dict);
                bf.DFSRun();
            }
        
            Console.WriteLine(ret);
        }

        public void DFS(int v, int p, List<int> lst)
        {
            if (v == 1)
            {
                countComb.Add(lst);
                return;
            }

            for (int i = p; i <= v; i++)
            {
                if (v % i == 0)
                {
                    var l = lst.ToList();
                    l.Add(i);
                    DFS(v / i, i, l);
                }
            }
        }

    }

    // libs ----------
    class BruteForceBit
    {
        public int[] F;
        private Action Process;
        public List<int> Comb;
        public Dictionary<int, int> Dict;

        public BruteForceBit(Action process, List<int> comb, Dictionary<int, int> dict)
        {
            Process = process;
            Comb = comb;
            Dict = dict;
            F = new int[Comb.Count];
        }

        public void DFSRun()
        {
            DFS(0);
        }

        private void DFS(int i)
        {
            if (i == Comb.Count)
            {
                Process();
            }
            else
            {
                foreach (var kv in Dict)
                {
                    if (kv.Value >= Comb[i] - 1)
                    {
                        F[i] = kv.Key;
                        if (i > 0 && Comb[i] == Comb[i - 1] && kv.Key < F[i - 1])
                            continue;

                        bool flg = true;
                        for (int j = 0; j < i; j++)
                        {
                            if (F[j] == F[i]) flg = false;
                        }

                        if (flg)
                        {
                            DFS(i + 1);
                        }
                    }
                }
            }
        }

    }

    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}