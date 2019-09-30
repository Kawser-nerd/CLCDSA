using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFile = @"E:\Visual Studio Projects\Google Code Jam\cj2012\GoogleCodeJam1C\ProblemB\Input\B-large.in";
            const string outputFile = @"E:\Visual Studio Projects\Google Code Jam\cj2012\GoogleCodeJam1C\ProblemB\Output\Large.txt";

            var sr = new StreamReader(inputFile);
            var sw = new StreamWriter(outputFile);

            int testCases = int.Parse(sr.ReadLine());
            for (int i = 1; i <= testCases; i++)
            {
                var testCase = ProbB.ParseCase(sr);
                var result = "Case #" + i + ": " + testCase.SolveCase();
                sw.WriteLine(result);
            }
            sw.Flush();
            sw.Close();
        }
    }

    public class ProbB
    {
        public double D { get; set; }
        public int N { get; set; }
        public int A { get; set; }
        public List<List<double>> Position { get; set; }
        public List<double> Acceleration { get; set; }
 
        public static ProbB ParseCase(StreamReader sr)
        {
            var parameters =
                sr.ReadLine()
                    .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

            var d = double.Parse(parameters.First());
            var n = int.Parse(parameters.Skip(1).First());
            var a = int.Parse(parameters.Last());

            var position =
                Enumerable.Range(0, n)
                    .Select(i => sr.ReadLine()
                                     .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                                     .Select(s => double.Parse(s))
                                     .ToList())
                    .ToList();

            var acceleration =
                sr.ReadLine()
                    .Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries)
                    .Select(s => double.Parse(s))
                    .ToList();

            return new ProbB {D = d, N = n, A = a, Position = position, Acceleration = acceleration};
        }

        public String SolveCase()
        {
            return "\r\n" + String.Join("\r\n", Acceleration.Select(a => SolveSingle(a).ToString()));
        }

        public double SolveSingle(double a)
        {
            var timeWait = 0.0;
            for (int i = 0; i < Position.Count; i++)
            {
                var ti = Position[i][0];
                var xi = Position[i][1];
                
                if(i == 0 && xi > D)
                    break;

                if(xi > D)
                {
                    var t0 = Position[i - 1][0];
                    var x0 = Position[i - 1][1];
                    var s = (xi - x0)/(ti - t0);
                    ti = t0 + (D - x0)/s;
                    xi = D;
                }

                var tx = Math.Sqrt(2*xi/a);

                if(ti > tx+timeWait)
                {
                    timeWait = ti - tx;
                }

                if(xi >= D)
                    break;
            }
            var freetime = Math.Sqrt(2*D/a);
            return freetime + timeWait;
        }
    }

}
