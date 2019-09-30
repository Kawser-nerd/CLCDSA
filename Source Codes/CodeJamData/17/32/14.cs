/*
 * Google CodeJam 2017: Round 1C
 * Problem A: Ample Syrup
 * Author: Mahmoud Aladdin <aladdin3>
 */

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace GoogleCodeJam2017
{
    class Program
    {
        static void Main(string[] args)
        {
            var listOfTasks = new List<IGCJTask>();

            using (var reader = new StreamReader("input.txt"))
            {
                var numberOfTestCases = int.Parse(reader.ReadLine());
                for (int i = 0; i < numberOfTestCases; i++)
                {
                    var task = new AmpleSyrup(i + 1);
                    task.ReadInput(reader);
                    listOfTasks.Add(task);
                }
            }

            int finishedTasks = 0;
            Parallel.ForEach(
                listOfTasks, 
                new ParallelOptions {
                    MaxDegreeOfParallelism = Math.Max(1, Environment.ProcessorCount - 1)
                }, 
                (task) => {
                    var stopwatch = new Stopwatch();
                    stopwatch.Start();
                    task.Solve();
                    stopwatch.Stop();

                    Interlocked.Increment(ref finishedTasks);
                    Console.Error.WriteLine($"Finished {finishedTasks} out of {listOfTasks.Count}. Time = {stopwatch.Elapsed.TotalSeconds} seconds");
                }
            );

            using (var writer = new StreamWriter("output.txt"))
            {
                foreach (var task in listOfTasks)
                {
                    task.WriteOutput(writer);
                }
            }
        }
    }

    interface IGCJTask
    {
        void ReadInput(StreamReader input);
        void Solve();
        void WriteOutput(StreamWriter output);
    }

    abstract class GCJTask : IGCJTask
    {
        public abstract void ReadInput(StreamReader input);
        public abstract void Solve();
        public abstract void WriteOutput(StreamWriter output);

        protected GCJTask(int caseNumber)
        {
            this.caseNumber = caseNumber;
        }

        protected int caseNumber;
        protected void debug(string msg)
        {
            Console.ForegroundColor = ConsoleColor.Magenta;
            Console.WriteLine($"[{caseNumber}][{DateTime.Now}] {msg}");
            Console.ResetColor();
        }
    }

    class AmpleSyrup : GCJTask {
        public AmpleSyrup(int caseNumber) : base(caseNumber)
        {

        }

        List<Tuple<int, int>> cA;
        List<Tuple<int, int>> jA;

        int[] forcedC;
        int[] forcedJ;

        public override void ReadInput(StreamReader input)
        {
            var tokens = input.ReadLine().Trim().Split();
            var cAC = int.Parse(tokens[0]);
            var jAC = int.Parse(tokens[1]);

            cA = new List<Tuple<int, int>>();
            for (int i = 0; i < cAC; i++)
            {
                tokens = input.ReadLine().Trim().Split();
                var intTokens = tokens.Select(item => int.Parse(item)).ToArray();
                cA.Add(Tuple.Create(intTokens[0], intTokens[1]));
            }

            jA = new List<Tuple<int, int>>();
            for (int i = 0; i < jAC; i++)
            {
                tokens = input.ReadLine().Trim().Split();
                var intTokens = tokens.Select(item => int.Parse(item)).ToArray();
                jA.Add(Tuple.Create(intTokens[0], intTokens[1]));
            }
        }

        int[][][] dp;

        private int SolveDP(int total, int forC, int prev)
        {
            if (total > 1440) return INF;

            var totalForC = forC + forcedC[total];
            var totalForJ = total - totalForC;
    if (totalForC > 720) return INF;
    if (totalForJ > 720) return INF;
            if (total == 1440) return prev == begin ? 0 : 1;

            if (dp[total][forC][prev] == -1)
            {
                var isAssC = forcedC[total];
                var isAssJ = forcedJ[total];
                if (total > 0) {
                    isAssC -= forcedC[total - 1];
                    isAssJ -= forcedJ[total - 1];
                }

                if (isAssC > 0 || isAssJ > 0) {
                    if (isAssC > 0) {
                        var cost = prev != 0 ? 1 : 0;
                        dp[total][forC][prev] = cost + SolveDP(total + 1, forC, 0);
                    }
                    if (isAssJ > 0) {
                        var cost = prev != 1 ? 1 : 0;
                        dp[total][forC][prev] = cost + SolveDP(total + 1, forC, 1);
                    }
                }
                else {
                    var cost = prev != 0 ? 1 : 0;
                    var res1 = cost + SolveDP(total + 1, forC + 1, 0);


                    cost = prev != 1 ? 1 : 0;
                    var res2 = cost + SolveDP(total + 1, forC, 1);

                    dp[total][forC][prev] = Math.Min(res1, res2);
                }
            }
            return dp[total][forC][prev];
        }

        int INF = int.MaxValue >> 1;
        int begin = 0;
        public override void Solve()
        {
            forcedC = new int[1441];
            foreach(var elem in jA)
            {
                for(int i = elem.Item1; i < elem.Item2; i++)
                {
                    forcedC[i] = 1;
                }
            }

            forcedJ = new int[1441];
            foreach (var elem in cA)
            {
                for (int i = elem.Item1; i < elem.Item2; i++)
                {
                    forcedJ[i] = 1;
                }
            }

            for(int i = 1; i <= 1440; i++)
            {
                forcedC[i] += forcedC[i - 1];
                forcedJ[i] += forcedJ[i - 1];
            }



            dp = new int[1441][][];
            for (int i = 0; i < 1441; i++)
            {
                dp[i] = new int[721][];
                for (int j = 0; j < 721; j++)
                {
                    dp[i][j] = new int[2];
                    dp[i][j][0] = -1;
                    dp[i][j][1] = -1;
                }
            }

            begin = 0;
            int res1 = SolveDP(0, 0, begin);

            for (int i = 0; i < 1441; i++)
            {
                for (int j = 0; j < 721; j++)
                {
                    dp[i][j][0] = -1;
                    dp[i][j][1] = -1;
                }
            }

            begin = 1;
            int res2  = SolveDP(0, 0, begin);
            solution = Math.Min(res1, res2);
        }



        int solution;

        public override void WriteOutput(StreamWriter output)
        {
            output.WriteLine($"Case #{caseNumber}: {solution}");
        }
    }

}
