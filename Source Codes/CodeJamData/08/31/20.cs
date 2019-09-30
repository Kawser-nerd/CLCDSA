using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TextMessagingOutrage
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            for (int case_nr = 1; case_nr <= N; case_nr++)
            {
                int P, K, L;
                {
                    string[] ss = Console.ReadLine().Split(' ');
                    P = int.Parse(ss[0]);
                    K = int.Parse(ss[1]);
                    L = int.Parse(ss[2]);
                }
                int[] tab = new int[L];
                {
                    string[] ss = Console.ReadLine().Split(' ');
                    for (int i = 0; i < L; i++)
                        tab[i] = int.Parse(ss[i]);
                }
                Console.WriteLine("Case #{0}: {1}", case_nr, MinPresses(P, K, L, tab));
            }
        }

        private static string MinPresses(int P, int K, int L, int[] tab)
        {
            {
                int needed = 0;
                for (int i = 0; i < L; i++)
                    if (tab[i] != 0)
                        needed++;
                if (needed > P * K)
                    return "Impossible";
            }
            Array.Sort(tab);
            long result = 0;
            for (int i = 0; i < L; i++)
            {
                long val = tab[L - i - 1];
                result += val * (1 + (i/K));
            }
            return result.ToString();
        }
    }
}
