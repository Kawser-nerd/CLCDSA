/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2010QualRound
{
    public class A_SnapperChain
    {
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {                
                int n = scanner.NextInt();
                int k = scanner.NextInt();
                int mask = (1 << n) - 1;
                var answer = (k & mask) == mask;
                output.WriteLine("Case #{0}: {1}", caseId, answer ? "ON" : "OFF");
            }
            output.Close();
        }

        static void Main(string[] args)
        {
            new A_SnapperChain().Solve(Console.In, Console.Out);
            new A_SnapperChain().Solve(new StreamReader("A-small-attempt1.in"), new StreamWriter("A-small.out"));
            new A_SnapperChain().Solve(new StreamReader("A-large.in"), new StreamWriter("A-large.out"));
        }
    }
}
