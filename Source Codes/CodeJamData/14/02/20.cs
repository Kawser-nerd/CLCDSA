using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace task2
{
    class Program
    {
        private static decimal CalcSum(decimal d, decimal f, int n)
        {
            var r = 0m;
            for (var i = 0; i < n; ++i)
            {
                r += 1/d;
                d += f;
            }
            return r;
        }

        private const decimal d_ = 2m;

        static void Main(string[] args)
        {
            TextReader reader = null;
            TextWriter writer = null;
            try
            {
                reader = new StreamReader(args[0], Encoding.ASCII);
                writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII);
                var cases = int.Parse(reader.ReadLine());
                Console.WriteLine("Cases {0}", cases);
                for (var i = 1; i <= cases; ++i)
                {
                    var parameters = reader.ReadLine().Split(new[] { ' ' });
                    var c = decimal.Parse(parameters[0], CultureInfo.InvariantCulture);
                    var f = decimal.Parse(parameters[1], CultureInfo.InvariantCulture);
                    var x = decimal.Parse(parameters[2], CultureInfo.InvariantCulture);

                    // занизили тут на 1 на всякий случай, чтобы не огрести проблемы с округлением
                    // без округления можно было бы сразу вычислить оптимальное n (n1 + 1)
                    var n1 = (int)Math.Floor(x/c - d_/f - 2);
                    if (n1 < 0)
                    {
                        n1 = 0;
                    }
                    var m = CalcSum(d_, f, n1) * c;
                    var cost1 = m +  x / (d_ + n1 * f);
                    var m2 = m + c / (d_ + n1 * f);
                    var cost2 = m2 + x / (d_ + n1 * f + f);
                    var cost3 = m2 + c / (d_ + n1 * f + f) + x / (d_ + n1 * f + 2 * f);
                    var cost = Math.Min(cost1, Math.Min(cost2, cost3));
                    var result = String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i, cost);
                    writer.WriteLine(result);
                }
            }
            finally
            {
                if (writer != null)
                    writer.Close();
                if (reader != null)
                    reader.Close();
            }
        }
    }
}
