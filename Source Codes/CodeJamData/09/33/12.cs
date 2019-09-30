using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static int mintotal;
        static int Solve(int[] aCells, int[] aHoles, int P, int Q, int total)
        {
            if (Q == 0)
            {
                if (mintotal > total)
                    mintotal = total;
                return 0;
            };
            if (total > mintotal)
            {
                return 1000000000;
            };
            int[] aCells2 = new int[Q - 1];
            int[] aHoles2 = new int[aHoles.Length + 1];
            for (int j = 0; j < aHoles.Length; ++j)
                aHoles2[j] = aHoles[j];

            int rslt = int.MaxValue;
            for (int i = 0; i < Q; ++i)
            {
                int k = 0;
                for (int j = 0; j < Q; ++j)
                {
                    if (j != i)
                    {
                        aCells2[k] = aCells[j];
                        ++k;
                    };
                };

                int localrslt = 0;
                for (int j = aCells[i] + 1; j <= P; ++j)
                {
                    if (aHoles.Contains(j))
                        break;
                    localrslt += 1;
                };
                for (int j = aCells[i] - 1; j > 0; --j)
                {
                    if (aHoles.Contains(j))
                        break;
                    localrslt += 1;
                };
                aHoles2[aHoles.Length] = aCells[i];
                localrslt += Solve(aCells2, aHoles2, P, Q - 1, total+localrslt);
                if (localrslt < rslt)
                    rslt = localrslt;
            };
            return rslt;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                int[] PQ = Console.ReadLine().Split(' ').Select((x)=>(int.Parse(x))).ToArray();
                int P = PQ[0];
                int Q = PQ[1];
                int[] cells = Console.ReadLine().Split(' ').Select((x) => (int.Parse(x))).ToArray();
                mintotal = int.MaxValue;
                int rslt = Solve(cells, new int[0], P, Q, 0);
//xxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxx
//  1  1       1

                Console.WriteLine("Case #{0}: {1}", i + 1, rslt);
            };
        }
    }
}
