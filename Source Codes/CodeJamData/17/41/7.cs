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
                    var task = new FreshChocolate(i + 1);
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

    class FreshChocolate : GCJTask {
        public FreshChocolate(int caseNumber) : base(caseNumber)
        {

        }

        int N;
        int P;

        List<int> groups;

        public override void ReadInput(StreamReader input)
        {
            var tokens = input.ReadLine().Trim().Split();
            this.N = int.Parse(tokens[0]);
            this.P = int.Parse(tokens[1]);

            tokens = input.ReadLine().Trim().Split();
            this.groups = tokens.Select(item => int.Parse(item)).ToList();
        }

        public override void Solve()
        {
            int[] div = new int[P];

            foreach(var val in groups)
            {
                div[val % P]++;
            }

            if(P == 2)
            {
                solution = div[0] + (div[1] >> 1);
                if(div[1] % 2 != 0)
                {
                    solution += 1;
                }
            }
            else if(P == 3)
            {
                bool changed = true;
                while(changed)
                {
                    changed = false;
                    var min = Math.Min(div[1], div[2]);
                    if(min > 0)
                    {
                        div[1] -= min;
                        div[2] -= min;
                        div[0] += min;
                        changed = true;
                    }
                    else if(div[1] > 2)
                    {
                        var mul = div[1] / 3;
                        div[0] += mul;
                        div[1] -= 3 * mul;
                        changed = true;
                    }
                    else if(div[2] > 2)
                    {
                        var mul = div[2] / 3;
                        div[0] += mul;
                        div[2] -= 3 * mul;
                        changed = true;
                    }
                }
                solution = div[0];
                if(div[1] > 0 || div[2] > 0)
                {
                    solution++;
                }
            }
            else if(P == 4)
            {
                dp = new int[101][][];
                for (int j = 0; j < dp.Length; j++)
                {
                    dp[j] = new int[101][];
                    for(int i = 0; i < dp[j].Length; i++)
                    {
                        dp[j][i] = Enumerable.Repeat<int>(-1, 101).ToArray();
                    }
                }

                solution = div[0];
                solution += SolveDP4(div[1], div[2], div[3]);
            }
        }

        int NINF = int.MinValue / 2;
        int[][][] dp;
        private int SolveDP4(int v1, int v2, int v3)
        {
            if (v1 >= dp.Length) return NINF;
            if (v2 >= dp[v1].Length) return NINF;
            if (v3 >= dp[v1][v2].Length) return NINF;
            if (dp[v1][v2][v3] == -2) return NINF;

            if(dp[v1][v2][v3] == -1)
            {
                dp[v1][v2][v3] = -2;

                var result = (v1 | v2 | v3) > 0? 1 : 0;
                if (v1 >= 1)
                {
                    if (v1 >= 2) result = Math.Max(result, SolveDP4(v1 - 2, v2 + 1, v3));
                    if (v2 >= 1) result = Math.Max(result, SolveDP4(v1 - 1, v2 - 1, v3 + 1));
                    if (v3 >= 1) result = Math.Max(result, 1 + SolveDP4(v1 - 1, v2, v3 - 1));
                }

                if (v2 >= 1)
                {
                    if (v2 >= 2) result = Math.Max(result, 1 + SolveDP4(v1, v2 - 2, v3));
                    if (v3 >= 1) result = Math.Max(result, SolveDP4(v1 + 1, v2 - 1, v3 - 1));
                }

                if(v3 >= 2)
                {
                    result = Math.Max(result, SolveDP4(v1, v2 + 1, v3 - 2));
                }

                dp[v1][v2][v3] = result;
            }
            return dp[v1][v2][v3];
        }

        int solution;

        public override void WriteOutput(StreamWriter output)
        {
            output.WriteLine($"Case #{caseNumber}: {solution}");
        }
    }

}
