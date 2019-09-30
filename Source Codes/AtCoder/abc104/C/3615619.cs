using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayInt();
            var D = input[0];
            var G = input[1];
            var P = new int[D];
            var C = new int[D];
            var bonus = new int[D];
            for (int i = 0; i < D; i++)
            {
                input = ReadArrayInt();
                P[i] = input[0];
                C[i] = input[1];
                bonus[i] = 100 * (i + 1) * P[i] + C[i];
            }
            var ans = int.MaxValue;
            for (int i = 0; i < (1 << D); i++)
            {
                var sum = 0;
                var cnt = 0;
                var end = new bool[D];
                for (int j = 0; j < D; j++) if ((i & (1 << j)) == (1 << j)) end[j] = true;
                for (int j = 0; j < D; j++) if (end[j]) { sum += bonus[j]; cnt += P[j]; }
                if (sum >= G && cnt < ans) { ans = cnt; continue; }
                else if (sum >= G) continue;
                for (int j = D - 1; j >= 0; j--)
                {                    
                    if (!end[j])
                    {
                        for (int k = 0; k < P[j]; k++)
                        {
                            sum += 100 * (j + 1);
                            if (k == P[j] - 1) sum += C[j];
                            cnt++;
                            if (sum >= G) break;                            
                        }
                    }
                    if (sum >= G) break;
                }
                if (cnt < ans) ans = cnt;
            }
            
            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}