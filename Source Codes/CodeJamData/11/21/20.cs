/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2011Round1B
{
    public class A_RPI
    {

        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                int n = scanner.NextInt();
                string[] match = new string[n];
                int[] win = new int[n];
                int[] total = new int[n];
                double[] wp = new double[n];
                double[] owp = new double[n];
                double[] oowp = new double[n];
                double[] rpi = new double[n];
                for (int i = 0; i < n; i++)
                {
                    match[i] = scanner.Next();
                    win[i] = match[i].Count(c => c == '1');
                    total[i] = match[i].Count(c => c != '.');
                    wp[i] = (double) win[i] / total[i];
                }
                for (int i = 0; i < n; i++)
                {
                    double sum = 0;
                    for (int j = 0; j < n; j++)
                        if (match[i][j] != '.')
                        {
                            if (match[j][i] == '1')
                                sum += (double) (win[j] - 1) / (total[j] - 1);
                            else
                                sum += (double) win[j] / (total[j] - 1);
                        }
                    owp[i] = sum / total[i]; 
                }
                for (int i = 0; i < n; i++)
                {
                    double sum = 0;
                    for (int j = 0; j < n; j++)
                        if (match[i][j] != '.')
                            sum += owp[j];
                    oowp[i] = sum / total[i];
                }
                output.WriteLine("Case #{0}:", caseId);
                for (int i = 0; i < n; i++)
                {
                    rpi[i] = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
                    output.WriteLine("{0}", rpi[i]);
                }
            }
            output.Close();
        }

        static void Main(string[] args)
        {
          //  new A_RPI().Solve(Console.In, Console.Out);
          //  new A_RPI().Solve(new StreamReader("A-small-attempt0.in"), new StreamWriter("A-small.out"));
            new A_RPI().Solve(new StreamReader("A-large.in"), new StreamWriter("A-large.out"));
        }
    }
}
