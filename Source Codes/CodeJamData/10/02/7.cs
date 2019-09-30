/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;
using System.Numerics;

namespace GCJ2010QualRound
{
    public class B_FairWarning
    {
        BigInteger GCD(BigInteger a, BigInteger b)
        {
            if (b == 0)
                return a;
            else
                return GCD(b, a % b);
        }
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                int n = scanner.NextInt();
                var t = Enumerable.Range(0, n).Select(i => BigInteger.Parse(scanner.Next())).ToArray();
                var m = t.Min();
                var d = t.Select(v => v - m).Where(v => v > 0).Aggregate(BigInteger.Zero, (s, v) => GCD(v, s));
                m %= d;
                output.WriteLine("Case #{0}: {1}", caseId,  m > 0 ? d - m : 0);
            }
            output.Close();
        }

        static void Main(string[] args)
        {
            new B_FairWarning().Solve(Console.In, Console.Out);
            new B_FairWarning().Solve(new StreamReader("B-small-attempt0.in"), new StreamWriter("B-small.out"));
            new B_FairWarning().Solve(new StreamReader("B-large.in"), new StreamWriter("B-large.out"));
        }

    }
}
