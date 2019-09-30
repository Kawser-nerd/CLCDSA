using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class C : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string[] s = Console.ReadLine().Split();
                int N = int.Parse(s[0]);
                int Q = int.Parse(s[1]);
                int[] horseRange = new int[N];
                int[] horseSpeed = new int[N];

                long[,] cityDis = new long[N, N];
                for (int i = 0; i < N; i++)
                {
                    s = Console.ReadLine().Split();
                    horseRange[i] = int.Parse(s[0]);
                    horseSpeed[i] = int.Parse(s[1]);
                }

                for (int i = 0; i < N; i++)
                {
                    s = Console.ReadLine().Split();
                    for (int j = 0; j < N; j++)
                    {
                        cityDis[i, j] = int.Parse(s[j]);
                    }
                }

                int[] city1 = new int[Q];
                int[] city2 = new int[Q];
                for (int i = 0; i < Q; i++)
                {
                    s = Console.ReadLine().Split();
                    city1[i] = int.Parse(s[0]);
                    city2[i] = int.Parse(s[1]);
                }
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(N, Q, horseRange, horseSpeed, cityDis, city1, city2)
                    );
                //tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(int N, int Q, int[] horseRange, int[] horseSpeed, long[,] cityDis, int[] city1, int[] city2)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (cityDis[i, j] == -1)
                    {
                        cityDis[i, j] = long.MaxValue / 1000;
                    }
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        cityDis[j, k] = Math.Min(cityDis[j, k], cityDis[j, i] + cityDis[i, k]);
                    }
                }
            }

            double[,] cityTime = new double[N, N];
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (cityDis[i, j] <= horseRange[i])
                    {
                        cityTime[i, j] = (double)cityDis[i, j] / horseSpeed[i];
                    }
                    else
                    {
                        cityTime[i, j] = double.MaxValue / 5000;
                    }
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        cityTime[j, k] = Math.Min(cityTime[j, k], cityTime[j, i] + cityTime[i, k]);
                    }
                }
            }

            StringBuilder ret = new StringBuilder();
            for (int i = 0; i < Q; i++)
            {
                if (i > 0) ret.Append(" ");
                ret.Append(cityTime[city1[i]-1, city2[i]-1]);
            }

            return ret.ToString();
        }
    }
}
