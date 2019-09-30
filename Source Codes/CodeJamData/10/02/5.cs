using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace task2
{
    class Program
    {
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
                    var N = int.Parse(parameters[0]);
                    var times = new BigInteger[N];
                    var minTime = BigInteger.Parse(parameters[1]);
                    var minIndex = 0;
                    for (var j = 0; j < N; ++j)
                    {
                        var v = BigInteger.Parse(parameters[j + 1]);
                        times[j] = v;
                        if (v < minTime)
                        {
                            minTime = v;
                            minIndex = j;
                        }                         
                    }
                    var currentIndex = 0;
                    if (currentIndex == minIndex)
                        ++currentIndex;
                    var gcd = times[currentIndex] - minTime;
                    for (++currentIndex; currentIndex < N; ++currentIndex)
                    {
                        var v = times[currentIndex];
                        if (v == minTime)
                            continue;
                        gcd = BigInteger.GreatestCommonDivisor(gcd, v - minTime);
                        if (gcd == 1)
                            break;
                    }
                    var rest = minTime % gcd;
                    var y = rest == 0 ? BigInteger.Zero : gcd - rest;
                    var result = String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i, y);
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
