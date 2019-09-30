/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2011Round2
{
    public class C_ExpensiveDinner
    {

       
        const int R = 1000000;
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            
            bool[] isPrime = new bool [R + 1];
            for (int i = 2; i <= R; i++)
                isPrime[i] = true;
            for (long i = 0; i <= R; i++)
                if (isPrime[i])
                    for (long j =  i * i; j <= R; j += i)
                        isPrime[j] = false;

            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                long n = scanner.NextLong();
                if (n == 1)
                {
                    output.WriteLine("Case #{0}: {1}", caseId, 0);
                }
                else
                {
                    int answer = 1;
                    for (long p = 2; p * p <= n; p++)
                        if (isPrime[p])
                        {
                            long s = p * p;
                            while (s <= n)
                            {
                                s *= p;
                                answer++;
                            }
                        }
                    output.WriteLine("Case #{0}: {1}", caseId, answer);
                }
            }
            output.Close();
        }

        static void Main(string[] args)
        {
             //    new C_ExpensiveDinner().Solve(Console.In, Console.Out);
           //  new C_ExpensiveDinner().Solve(new StreamReader("C-small-attempt0.in"), new StreamWriter("C-small.out"));
            new C_ExpensiveDinner().Solve(new StreamReader("C-large.in"), new StreamWriter("C-large.out"));
        }
    }
}
