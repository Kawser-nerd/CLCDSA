using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static TextReader input = Console.In;
        static TextWriter output = Console.Out;
        static void Main(string[] args)
        {
            if (args.Any())
            {
                var path = args[0];
                if (File.Exists(path))
                {
                    input = File.OpenText(path);
                }
                path = path.Remove(path.LastIndexOf('.'));
                path += ".out";
                output = File.CreateText(path);
            }

            int totalCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= totalCases; currentCase++)
            {
                string caseOutput = HandleCase(input);
                output.WriteLine(string.Format("Case #{0}: {1}", currentCase, caseOutput));
                output.Flush();
            }
        }

        private static string HandleCase(TextReader input)
        {
            long[] numbers = input.ReadLine().Split(' ').Select(long.Parse).ToArray();
            BigInteger a = numbers[0];
            BigInteger b = numbers[1];
            BigInteger k = numbers[2];

            // if a <= k or b <= k all numbers are valid
            if (a <= k || b <= k)
            {
                return (a * b).ToString();
            }

            BigInteger validCount = 0;
            // add all we're sure are valid
            validCount += a * k + b * k - k * k;
            // add remainder
            for (long i = (long) k; i < a; i++)
            {
                for (long j = (long) k; j < b; j++)
                {
                    if ((i & j) < k)
                    {
                        validCount++;
                    }
                }
            }

            return validCount.ToString();
        }
    }
}
