using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ13_1A_C
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            Console.WriteLine("Case #1:");
            string[] ss = Console.ReadLine().Split(' ');
            int R = int.Parse(ss[0]);
            int N = int.Parse(ss[1]);
            int M = int.Parse(ss[2]);
            int K = int.Parse(ss[3]);

            SortedDictionary<int, List<int>> pc = new SortedDictionary<int, List<int>>();
            for (int i = 4; i < 512; i++)
            {
                if ((i & 3) == 0)
                {
                    int mul = 1;
                    for (int j = 2; j <= 8; j++)
                        if ((i & 1 << j) == (1 << j)) mul *= j;
                    if (!pc.ContainsKey(mul)) pc[mul] = new List<int>();
                    pc[mul].Add(i);
                }
            }

            TimeSpan ts = new TimeSpan(0,3,0);
            ts = new TimeSpan(ts.Ticks/R);

            Random rand = new Random();
            for (int i = 0; i < R; i++)
            {
                ss = Console.ReadLine().Split(' ');
                HashSet<int> pi = new HashSet<int>();
                for (int j = 0; j < ss.Length; j++) if (ss[j] != "1") pi.Add(int.Parse(ss[j]));

                int[] opi = new int[pi.Count];
                pi.CopyTo(opi);

                DateTime start = DateTime.Now;
                bool found = false;
                if (pi.Count > 0)
                {
                    while (DateTime.Now < start + ts)
                    {
                        pi = new HashSet<int>(opi);

                        int[] n = new int[N];
                        for (int j = 0; j < N; j++) n[j] = rand.Next(2, M+1);

                        for (int j = 0; j < (1 << N) && pi.Count>0; j++)
                        {
                            int mul = 1;
                            for (int k = 0; k < N; k++)
                                if ((j & (1 << k)) == (1 << k)) mul *= n[k];

                            pi.Remove(mul);
                        }

                        if (pi.Count == 0)
                        {
                            for (int j = 0; j < N; j++) Console.Write(n[j]);
                            Console.WriteLine();
                            found = true;
                            break;
                        }
                    }
                }

                if (!found)
                {
                    for (int j = 0; j < N; j++) Console.Write(2);
                    Console.WriteLine();
                }
            }
        }
    }
}
