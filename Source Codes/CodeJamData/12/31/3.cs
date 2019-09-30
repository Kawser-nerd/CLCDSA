using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace _2012Q
{
    class _1C_A
    {

        static void Main(string[] args)
        {


            int T;

            string str;
            str = Console.ReadLine();
            T = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                int N,M;
                str = Console.ReadLine();
                string[] strs = str.Split(' ');
                N = int.Parse(strs[0]);

                int[][] Parents = new int[N][];
                List<int>[] Sosen = new List<int>[N];

                for (int i = 0; i < N; i++)
                {
                    str = Console.ReadLine();
                    strs = str.Split(' ');

                    M = int.Parse(strs[0]);
                    Parents[i] = new int[M];
                    for (int j = 0; j < M; j++)
                    {
                        Parents[i][j] = int.Parse(strs[j+1]) -1;
                    }
                }

                bool Found = false;
                while (!Found && Sosen.Any(x=>x==null))
                {
                    for (int i = 0; i < N; i++)
                    {
                        if (Sosen[i] != null) { continue; }
                        if (!Parents[i].All(x => Sosen[x] != null)) { continue; }

                        Sosen[i] = Parents[i].SelectMany(x => Sosen[x]).ToList();
                        Sosen[i].AddRange(Parents[i]);
                        if (Sosen[i].Count != Sosen[i].Distinct().Count())
                        {
                            Found = true;
                        }
                    }

                }


                Console.Write("Case #" + caseNumber + ": "+ (Found?"Yes":"No"));
                Console.WriteLine();
            }

            Console.ReadLine();
        }


    }
}
