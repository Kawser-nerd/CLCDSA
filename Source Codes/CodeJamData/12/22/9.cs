using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        const string InputPath = @"d:\Work\Current\CodeJam\2012-1B\2\B-large.in";
        const string OutputPath = @"d:\Work\Current\CodeJam\2012-1B\2\B-large.out";


        static void Main(string[] args)
        {

            var sr = new StreamReader(InputPath);
            var sw = new StreamWriter(OutputPath);

            int N = Int32.Parse(sr.ReadLine());
            for (int n = 1; n <= N; n++)
            {
                var x = SolveNextInput(sr);
                Console.WriteLine("Processing #" + n);
                sw.WriteLine(GetCaseSolutionString(x, n));

            }
            sr.Close();
            sw.Close();
        }

        private static string GetCaseSolutionString(string result, int n)
        {
            return string.Format("Case #{0}: {1}", n, result);
        }

        private static string SolveNextInput(StreamReader sr)
        {
            string phrase = sr.ReadLine();
            var nums = phrase.Split(' ').Select(int.Parse).ToList();
            int Level = nums[0];
            int N = nums[1]; //row
            int M = nums[2]; // col
            int [,] mapC = new int[N,M];
            int [,] mapF = new int[N,M];

            for (int i = 0; i < N; i++)
            {
                phrase = sr.ReadLine();
                nums = phrase.Split(' ').Select(int.Parse).ToList();
                for (int j = 0; j < M; j++)
                {
                    mapC[i, j] = nums[j];
                }
            }

            for (int i = 0; i < N; i++)
            {
                phrase = sr.ReadLine();
                nums = phrase.Split(' ').Select(int.Parse).ToList();
                for (int j = 0; j < M; j++)
                {
                    mapF[i, j] = nums[j];
                }
            }

            double [,] times = new double[N,M];
            bool [,] marks = new bool[N,M];
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    times[i, j] = double.PositiveInfinity;
                }
            }

            times[0, 0] = 0;
            bool bChanged = true;

            while (bChanged)
            {
                bChanged = false;
                var listOfCells = new List<Tuple<int, int>>();
                // find 0 reachable
                double max = double.PositiveInfinity;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        List<Tuple<int, int>> adj = GetListOfAdjustentCells(i, j, N, M);
                        foreach (var adjCell in adj)
                        {
                            int i1 = adjCell.Item1;
                            int j1 = adjCell.Item2;
                            if (times[i1, j1] > times[i, j])
                            {
                                if (CanMoveNoWater(i, j, i1, j1, mapC, mapF))
                                {
                                    double timeToMove = WhenCanMoveWithWater(i, j, i1, j1, mapC, mapF, Level,
                                                                             times[i, j]);
                                    if (times[i1, j1] > timeToMove)
                                    {
                                        times[i1, j1] = timeToMove;
                                        bChanged = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }


            string result = times[N-1, M-1].ToString("F6");

            return result;
        }

        private static double WhenCanMoveWithWater(int i, int j, int i1, int j1, int[,] mapC, int[,] mapF, int Level, double starttime)
        {
            double currentLevel = Level - (10.0*starttime);
            double res = 0;
            double left = Math.Max(currentLevel, (double)(mapF[i, j]));
            double right = mapC[i1, j1];
            double r = (50 - (right - left)) / 10.0;
            if (r < 0)
            {
                r = 0;
            }
            double thenLevel = currentLevel - (10.0*r);

            if (r == 0 && starttime == 0)
                return 0;

            if (thenLevel - 20 >= mapF[i,j])
            {
                res = starttime + r + 1;
            }
            else
            {
                res = starttime + r + 10;
            }

            return res;
        }

        private static bool CanMoveNoWater(int i, int j, int i1, int j1, int[,] mapC, int[,] mapF)
        {
            var minCiel = Math.Min(mapC[i, j], mapC[i1, j1]);
            var maxFloor = Math.Max(mapF[i, j], mapF[i1, j1]);
            if (minCiel - maxFloor >= 50)
                return true;
            return false;
        }

        private static List<Tuple<int, int>> GetListOfAdjustentCells(int i, int j, int N, int M)
        {
            var result = new List<Tuple<int, int>>();
            //left
            if (j-1 >= 0)
            {
                result.Add(new Tuple<int, int>(i, j - 1));
            }
            //top
            if (i-1 >= 0)
            {
                result.Add(new Tuple<int, int>(i - 1, j));
            }
            //Right
            if (j + 1 < M)
            {
                result.Add(new Tuple<int, int>(i, j + 1));
            }
            //bottom
            if (i + 1 < N)
            {
                result.Add(new Tuple<int, int>(i + 1, j));
            }
            return result;
        }

    }

}

