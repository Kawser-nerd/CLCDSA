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
    public class A_FileFixit
    {
        private int AddPath(HashSet<string> d, string s)
        {
           if (d.Contains(s))
               return 0;
           int answer = AddPath(d, s.Substring(0, s.LastIndexOf('/'))) + 1;
           d.Add(s);
           return answer;
        }
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {                
                int n = scanner.NextInt();
                int m = scanner.NextInt();
                var s = new HashSet<string>();
                s.Add("");
                for (int i = 0; i < n; i++)
                    AddPath(s, scanner.Next());
                int answer = 0;
                for (int i = 0; i < m; i++)
                    answer += AddPath(s, scanner.Next());
                output.WriteLine("Case #{0}: {1}", caseId, answer);
            }
            output.Close();
        }

        static void Main(string[] args)
        {
            new A_FileFixit().Solve(Console.In, Console.Out);
            new A_FileFixit().Solve(new StreamReader("A-small-attempt0.in"), new StreamWriter("A-small.out"));
            new A_FileFixit().Solve(new StreamReader("A-large.in"), new StreamWriter("A-large.out"));
        }
    }
}
