using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        const string InputPath = @"d:\Work\Current\CodeJam\2012-1B\1\A-small-attempt1.in";
        const string OutputPath = @"d:\Work\Current\CodeJam\2012-1B\1\A-small-attempt1.out";


        static void Main(string[] args)
        {

            var sr = new StreamReader(InputPath);
            var sw = new StreamWriter(OutputPath);

            int N = Int32.Parse(sr.ReadLine());
            for (int n = 1; n <= N; n++)
            {
                var x = SolveNextInput(sr);

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
            var nums = phrase.Split(' ').Select(t=>int.Parse(t)).ToList();
            int N = nums[0];
            var J = nums.Skip(1).ToList();
            var X = J.Sum();

            List<double> res = new List<double>();
            //if (N == 2)
            //{
            //    double y1 = ((double)(J[1] + X - J[0])) / (2 * X);
            //    if (y1 > 0)
            //    {
            //        res.Add(y1);
            //    }
            //    else
            //    {
            //        res.Add(0);
            //    }
            //    double y2 = ((double)(J[0] + X - J[1])) / (2 * X);
            //    if (y2 > 0)
            //    {
            //        res.Add(y2);
            //    }
            //    else
            //    {
            //        res.Add(0);
            //    }
            //}
            for (int i = 0; i < N; i++)
            {
                var current = J[i];
                var rest = J.ToList(); rest.RemoveAt(i);
                int j = 0;
                int KSum = 0;
                for (int k = 0; k < rest.Count; k++)
                {
                    var cc = rest[k];
                    if ((X+X - (N * cc) < 0))
                    {
                        KSum += cc;
                        j++;
                    }
                }
                double ress = ((double) (X + X - KSum - (N - j) * current))/((N - j)*X);
                var y2 = ress;
                if (y2 > 0)
                {
                    res.Add(y2);
                }
                else
                {
                    res.Add(0);
                }
            }

            var sb = new StringBuilder();
            foreach (var re in res)
            {
                sb.Append((re * 100.0).ToString("F6")).Append(" ");
            }
            
            string result = sb.ToString().Trim();

            return result;
        }

    }

}
