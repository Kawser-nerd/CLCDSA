using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AllSearch
{
    class ABC_002_D
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);

            bool[,] relation = new bool[n, n];
            for (int i = 0; i < m; i++)
            {
                string[] inRelation = Console.ReadLine().Split(' ');
                int man = int.Parse(inRelation[0]) - 1;
                int rel = int.Parse(inRelation[1]) - 1;
                relation[man, rel] = true;
                relation[rel, man] = true;
            }
            for(int i = 0; i < n; i++)
            {
                relation[i, i] = true;
            }

            int max = (int)Math.Pow(2, n);
            int maxRel = 1;
            for (int i = 1; i < max; i++)
            {
                int cnt = 0;
                bool ok = true;
                for (int j = 0; j <n; j++)
                {
                    if (((i >> j) & 1) == 1)
                    {
                        for (int k = 0; k < n; k++)
                        {
                            if (!relation[j, k] && ((i >> k) & 1) == 1)
                            {
                                ok = false;
                                break;
                            }
                        }
                        cnt++;
                    }
                }

                if (ok && maxRel < cnt)
                {
                    maxRel = cnt;
                }
            }
            Console.WriteLine(maxRel);
        }
    }
}