using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C080
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<bool[]> Flist = new List<bool[]>();
            List<int[]> Plist = new List<int[]>();
            for (int i = 0; i < N; i++)
            {
                bool[] F = Console.ReadLine().Split(' ').Select(x => x == "1").ToArray();
                Flist.Add(F);
            }
            for (int i = 0; i < N; i++)
            {
                int[] P = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                Plist.Add(P);
            }

            int pmax = int.MinValue;
            for(int i = 1; i < 1024; i++)
            {                
                int k = i;
                bool[] op = new bool[10];
                for (int j = 0; j < 10; j++)
                {
                    op[j] = k % 2 == 1;
                    k /= 2;
                }

                int pall = 0;
                for(int j = 0; j < Flist.Count; j++)
                {
                    int c = 0;
                    bool[] F = Flist[j];
                    for (int m = 0; m < 10; m++)
                    {
                        if (op[m] && F[m]) c++;
                    }
                    int[] P = Plist[j];
                    pall += P[c];
                }

                if (pall > pmax) pmax = pall;
            }
            Console.WriteLine(pmax);
        }
    }
}