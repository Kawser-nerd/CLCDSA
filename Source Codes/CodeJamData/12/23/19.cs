using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;

namespace _1b_c_sums
{
    class Program
    {
        static void Solve()
        {
            string s = Console.ReadLine();
            string[] sa = s.Split(' ');
            int cnt = int.Parse(sa[0]);
            long[] V = new Int64[cnt]; // long === Int64

            for (int i = 1; i <= cnt; ++i)
                V[i-1] = long.Parse(sa[i]);
            Array.Sort(V);

            Dictionary<long, int> M = new Dictionary<long, int>(); // suma --> index elementu w V
            M[0] = -1;

            for (int i = 0; i < cnt; ++i)
            {
                long w = V[i];
                Dictionary<long, int> M2 = new Dictionary<long, int>(M);
                foreach (KeyValuePair<long, int> d in M2)
                {
                    if (d.Value == i) continue;
                    long w2 = d.Key + w;
                    if (!M2.ContainsKey(w2))
                        M[w2] = i;
                    else
                    {
                        // match! do w2 można dotrzeć albo z w2-V[M[ws2]] albo z w2-V[i]
                        int j; long k;
                        SortedSet<int> s1 = new SortedSet<int>(), s2 = new SortedSet<int>();

                        // s1
                        k = w2; j = M[w2];
                        while (j >= 0)
                        {
                            s1.Add(j);
                            k -= V[j];
                            j = M[k];
                        }

                        // s2
                        k = w2; j = i;
                        while (j >= 0)
                        {
                            s2.Add(j);
                            k -= V[j];
                            j = M[k];
                        }

                        // diff
                        SortedSet<int> sb = new SortedSet<int>(s1);
                        sb.IntersectWith(s2);
                        s1.ExceptWith(sb);
                        s2.ExceptWith(sb);
                        
                        // out
                        foreach (int a in s1) Console.Write("{0} ", V[a]);
                        Console.WriteLine();
                        foreach (int a in s2) Console.Write("{0} ", V[a]);
                        Console.WriteLine();
                        return;
                    }
                }
            }

            Console.WriteLine("Impossible");
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture("en-US");
            int nCases = int.Parse(Console.ReadLine());
            for (int c = 1; c <= nCases; ++c)
            {
                Console.WriteLine("Case #{0}:", c);
                Solve();
            }
            //Console.ReadKey();
        }
    }
    /*
2
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600
     * */
}
