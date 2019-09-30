using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFileName = "B-large.in";
            const string outputFileName = "B-large.out.txt";
            var input = new StreamReader(inputFileName);
            var output = new StreamWriter(outputFileName);
            var tc = int.Parse(input.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                var d = new double[6];
                var n = int.Parse(input.ReadLine());
                for (int i = 0; i < n; i++)
                {
                    var temp = Array.ConvertAll(input.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), x => double.Parse(x));
                    for (int j = 0; j < 6; j++)
                    {
                        d[j] += temp[j] / n;
                    }
                }
                var a = (d[3]*d[3] + d[4]*d[4] + d[5]*d[5]);
                var b = 2 * (d[3] * d[0] + d[4] * d[1] + d[5] * d[2]);
                var c = (d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
                if (Math.Abs(a) < 1e-8)
                {
                    output.WriteLine("Case #{0}: {1:0.00000000} {2:0.00000000}", t + 1, Math.Sqrt(Math.Max(c, 0)), 0);
                    continue;
                }
                var tmin = Math.Max(-b/(2*a), 0);
                output.WriteLine("Case #{0}: {1:0.00000000} {2:0.00000000}", t + 1, Math.Sqrt((double)Math.Max(a * tmin * tmin + b * tmin + c, 0)), tmin);
            }
            output.Close();
        }
    }
}
