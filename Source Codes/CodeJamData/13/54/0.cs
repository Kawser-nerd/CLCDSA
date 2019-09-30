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
                string nextLine = input.ReadLine();
                if (nextLine == null) return null;
                words = nextLine.Trim().Split();
                wordCount = 0;
            }
            return words[wordCount++];
        }

        protected int[] NextInts(int n)
        {
            var returnValue = new int[n];
            for (int i = 0; i < n; i++)
                returnValue[i] = NextInt();
            return returnValue;
        }

        protected long[] NextLongs(int n)
        {
            var returnValue = new long[n];
            for (int i = 0; i < n; i++)
                returnValue[i] = NextLong();
            return returnValue;
        }

        protected double[] NextDoubles(int n)
        {
            var returnValue = new double[n];
            for (int i = 0; i < n; i++)
                returnValue[i] = NextDouble();
            return returnValue;
        }

        protected string[] NextWordsInLine()
        {
            return input.ReadLine().Trim().Split();
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

        protected string NextLine()
        {
            return input.ReadLine();
        }
        #endregion

        private bool _preSolved = false;

        public void Solve(string inputFile, string outputFile)
        {
            string result;

            if (!_preSolved)
            {
                PreSolve();
                _preSolved = true;
            }

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

        /// <summary>
        /// This method will be executed once before all testCases. Can do preprocessing here.
        /// </summary>
        protected virtual void PreSolve() { }

        protected abstract object Solve(StreamReader input);

        protected void log(String msg)
        {
            Console.WriteLine(msg);
        }
    }
}
