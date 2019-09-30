using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static int index(List<List<int>> lists, int n)
        {
            int total = 0;
            foreach (List<int> l in lists)
            {
                if (l.Count > n - total)
                    return l[n - total];
                total += l.Count;
            }
            throw new ApplicationException();
        }
        static void remove(List<List<int>> lists, int n)
        {
            int total = 0;
            foreach (List<int> l in lists)
            {
                if (l.Count > n - total)
                {
                    l.RemoveAt(n - total);
                    return;
                }
                total += l.Count;
            }
            throw new ApplicationException();
        }
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(args[0]);
            int T = int.Parse(sr.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int K = int.Parse(sr.ReadLine());
                int[] chosenCards = new int[K];
                List<List<int>> indices = new List<List<int>>();
                for (int i = 0; i < K; i++)
                {
                    if (i % 1000 == 0)
                        indices.Add(new List<int>());
                    indices[i / 1000].Add(i);
                }
                int nextindexindex = 0;
                for (int i = 1; i <= K; i++)
                {
                    //if (i%10000==0)
                    //    Console.WriteLine(i);
                    nextindexindex = (nextindexindex + i - 1) % (K+1-i);
                    chosenCards[index(indices, nextindexindex)] = i;
                    remove(indices, nextindexindex);
                    //indicesleft.RemoveAt(nextindexindex);
                    if (nextindexindex == K - i)
                    {
                        nextindexindex = 0;
                    }
                }
                Console.Write("Case #{0}:", t);
                string[] split = sr.ReadLine().Split();
                for (int i = 1; i < split.Length; i++)
                {
                    Console.Write(" {0}", chosenCards[int.Parse(split[i]) - 1]);
                }
                Console.WriteLine();
            }
        }
    }
}
