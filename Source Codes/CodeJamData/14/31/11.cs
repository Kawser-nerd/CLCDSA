using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace first
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var parameters = inputStream.ReadLine().Split('/').Select(s => long.Parse(s)).ToArray();
                    var p = parameters[0];
                    var q = parameters[1];

                    var beginning = 1L << 40;

                    //var factorsP = factors(p);
                    //var factorsQ = factors(q);

                    //factorsP.IntersectWith(factorsQ);

                    //var maxFactor = factorsP.Max();

                    //p = p / maxFactor;
                    //q = q / maxFactor;

                    var top = p * beginning;

                    if (top % q == 0)
                    {
                        var x = top / q;
                        var generations = 41;
                        while (x > 0)
                        {
                            x = x >> 1;
                            generations--;
                        }
                        outputStream.WriteLine("Case #{0}: {1}", caseNumber, generations);
                    }
                    else
                    {
                        outputStream.WriteLine("Case #{0}: impossible", caseNumber);
                    }


                }
            }
        }

        private static HashSet<long> factors(long p)
        {
            var result = new HashSet<long>();
            for (var i = 1; i <= p / 2; i++)
                if (p % i == 0)
                    result.Add(i);
            return result;
        }
    }
}
