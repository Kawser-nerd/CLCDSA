using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2016Round2
{
    public class ProblemB
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Round2\";

        public void Process()
        {
            var result = new StringBuilder();
            using (var tr = File.OpenText(Path + "in_B.txt"))
            {
                var testsCount = int.Parse(tr.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var p = tr.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    var n = p[0];
                    var k = p[1];
                    var arr = tr.ReadLine().Split(' ').Select(double.Parse).ToArray();
                    var r = Solve(arr, k);
                    result.AppendLine($"Case #{t}: {r}");
                }
            }
            using (var textWriter = File.CreateText(Path + "out_B.txt"))
                textWriter.Write(result.ToString());
        }

        private double Solve(double[] arr, int k)
        {
            var n = arr.Length;
            Array.Sort(arr);

            var max = double.MinValue;
            for (int i = 0; i <= k; ++i)
            {
                var list = new List<double>();
                list.AddRange(arr.Take(i));
                list.AddRange(arr.Skip(n - k + i).Take(k - i));
                var p = GetProbability(list.ToArray());
                if (p > max)
                    max = p;
            }
            return max;
        }

        public double GetProbability(double[] arr)
        {
            var k = arr.Length;
            var dp = new double[k + 1, k + 1];
            dp[0, 0] = 1;
            for (int j = 1; j <= k; ++j)
                for (int i = 0; i <= j; ++i)
                    dp[j, i] = dp[j - 1, i] * (1 - arr[j - 1]) + (i > 0 ? dp[j - 1, i - 1] * arr[j - 1] : 0);

            return dp[k, k / 2];
        }
    }
}
