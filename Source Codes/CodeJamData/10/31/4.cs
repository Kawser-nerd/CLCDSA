using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Solvers
{
    public abstract class AbstractSolver
    {
        public static void Main(string[] args)
        {
            Type typ = Type.GetType(args[0]);
            string input = args[1];
            string output = args[2];

            var solver = System.Activator.CreateInstance(typ) as AbstractSolver;
            solver.Solve(input, output);
        }

        private const string ResponseFormat = "Case #{0}: {1}";

        
        #region I/O helpers
        private StreamReader input;
        private string[] words;
        private int wordCount;

        protected string NextWord()
        {
            if (words == null || wordCount == words.Length)
            {
                words = input.ReadLine().Split();
                wordCount = 0;
            }
            return words[wordCount++];
        }

        protected int NextInt()
        {
            return int.Parse(NextWord());
        }

        protected long NextLong()
        {
            return long.Parse(NextWord());
        }

        protected double NextDouble()
        {
            return double.Parse(NextWord());
        }
        #endregion

        public void Solve(string inputFile, string outputFile)
        {
            string result;

            using (input = new StreamReader(inputFile))
            {
                using (StreamWriter output = new StreamWriter(outputFile, false))
                {

                    int testNo = NextInt();
                    for (int i = 1; i <= testNo; i++)
                    {
                        var obj = Solve(input);
                        result = (obj != null) ? obj.ToString() : "IMPOSSIBLE";
                        
                        output.WriteLine(String.Format(ResponseFormat, i, result));
                        Console.WriteLine(String.Format(ResponseFormat, i, result));
                    }
                }
            }
            Console.WriteLine("Koniec");
        }

        protected abstract object Solve(StreamReader input);
    }
}
