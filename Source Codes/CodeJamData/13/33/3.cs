using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace codejam2013
{
    public class P2CC
    {
        private const string mInputFile = @"E:\work\codejam2013\data\C-small-attempt0.in";
        private StreamWriter mOutput;
        private StreamReader mInput;

        static void Main(string[] args)
        {
            var p = new P2CC();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(mInputFile);
            Console.WriteLine(mInputFile + ".out");
            using (mOutput = new StreamWriter(mInputFile + ".out"))
            using (mInput = new StreamReader(mInputFile))
            {
                int testNum = int.Parse(mInput.ReadLine());
                for (int i = 0; i < testNum; i++)
                {
                    WriteResult(i + 1, RunTest());
                }
            }
        }

        struct Attack
        {
            public int Day { get; set; }
            public int W { get; set; }
            public int E { get; set; }
            public int S { get; set; }
        }

        private string RunTest()
        {
            int n = ReadIntsFromLine()[0];
            int[] d = new int[n];
            int[] ni = new int[n];
            int[] w = new int[n];
            int[] e = new int[n];
            int[] s = new int[n];
            int[] dd = new int[n];
            int[] dp = new int[n];
            int[] ds = new int[n];

            for (int i = 0; i < n; i++)
            {
                var ints = ReadIntsFromLine();
                d[i] = ints[0];
                ni[i] = ints[1];
                w[i] = ints[2];
                e[i] = ints[3];
                s[i] = ints[4];
                dd[i] = ints[5];
                dp[i] = ints[6];
                ds[i] = ints[7];
            }

            List<Attack> attacks = new List<Attack>();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < ni[i]; j++)
                {
                    Attack attack = new Attack()
                                        {
                                            Day = d[i] + j*dd[i],
                                            W = w[i] + j*dp[i],
                                            E = e[i] + j*dp[i],
                                            S = s[i] + j*ds[i]
                                        };

                    attacks.Add(attack);
                }
            }

            var attacksByDay = attacks.OrderBy(x => x.Day).GroupBy(x => x.Day);

            const int mid = 50000;
            int[] walls = new int[2*mid];
            int successes = 0;
            foreach (var atks in attacksByDay.Select(x => x.ToArray()))
            {
                foreach (var attack in atks)
                {
                    bool success = false;
                    for (int i = attack.W; i < attack.E; i++)
                    {
                        if (walls[i + mid] < attack.S)
                        {
                            success = true;
                            break;
                        }
                    }

                    if (success)
                    {
                        successes++;
                    }
                }

                // build walls
                foreach (var attack in atks)
                {
                    for (int i = attack.W; i < attack.E; i++)
                    {
                        if (walls[i + mid] < attack.S)
                        {
                            walls[i + mid] = attack.S;
                        }
                    }
                }
            }
            return "" + successes;
        }

        #region Utilities Methods

        private int[] ReadIntsFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => int.Parse(x)).ToArray();
        }

        private double[] ReadDoublesFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => double.Parse(x)).ToArray();
        }

        private IEnumerator<string> ReadStrings()
        {
            string line = null;
            while ((line = mInput.ReadLine()) != null)
            {
                foreach (string split in line.Split())
                    yield return split;
            }
        }

        private void WriteResult(int testNum, string result)
        {
            mOutput.WriteLine(string.Format("Case #{0}: {1}", testNum, result));
        }

        #endregion
    }
}
