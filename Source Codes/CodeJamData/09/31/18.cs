using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Windows.Forms;

namespace TaskSolution
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] sep = { ' ' };
            
            TextReader tr = new StreamReader(Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "input.txt"));
            TextWriter tw = new StreamWriter(@"c:\output.txt");

            int caseMax = Convert.ToInt32(tr.ReadLine());
            for (int caseIndex = 0; caseIndex < caseMax; caseIndex++)
            {
                long solution = 0;

                Dictionary<char, int> symbols = new Dictionary<char, int>();
                string input = tr.ReadLine().Trim();

                symbols.Add(input[0], 1);
                int maxv = 0;
                for (int i = 1; i < input.Length; i++)
                {
                    char c = input[i];
                    if (!symbols.ContainsKey(c))
                    {
                        if (maxv == 1)
                            maxv = 2;
                        symbols.Add(c, maxv);
                        maxv++;
                    }
                }
                solution = 0;
                if (maxv == 1 || maxv == 0)
                {
                    maxv = 2;
                }
                long b = 1;
                for (int i = input.Length - 1; i > -1; i--)
                {
                    long v = symbols[input[i]];
                    solution = solution + b * (v);
                    b = b * maxv;
                }


                Console.WriteLine(String.Format("Case #{0}: {1}", caseIndex + 1, solution));
                tw.WriteLine(String.Format("Case #{0}: {1}", caseIndex + 1, solution));
            }
            tw.Close();
            Console.WriteLine("Ready:)");
            Console.ReadLine();

        }
    }
}
