using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJamPractice
{
    /// <summary>
    /// Reads a tipical Input for Google Code Jam's Problems, started by a line containing T, followed by T
    /// test cases
    /// </summary>
    class CodeJamInput
    {
        string input = File.ReadAllText(@"c:\users\cecilia\documents\visual studio 2010\Projects\GoogleCodeJamPractice\GoogleCodeJamPractice\input.in");

        public CodeJamProblem[] problems;
        string[] lines;
        int currentLine = 0;

        public string NextLine()
        {
            return lines[currentLine++];
        }

        public CodeJamInput()
        {
            lines = input.Replace("\r", "").Split('\n');
            int T = int.Parse(NextLine());

            problems = new CodeJamProblem[T];

            for (int i = 0; i < T; ++i)
            {
                problems[i] = new CodeJamProblem().BuildProblem(this);
                problems[i].Number = i + 1;
            }
        }
    }

    class Program
    {
        static string outputPath = @"c:\users\cecilia\documents\visual studio 2010\Projects\GoogleCodeJamPractice\GoogleCodeJamPractice\output.out";

        static void Main(string[] args)
        {
            //Reads the input
            CodeJamInput input = new CodeJamInput();
            StringBuilder output = new StringBuilder();

            foreach (CodeJamProblem p in input.problems)
            {
                //Solves each test case
                output.AppendLine(p.GetSolution());
            }

            //Print results to file
            File.WriteAllText(outputPath, output.ToString());
        }
    }

    /// <summary>
    /// Actual class to be implemented during contest, represents a test case
    /// </summary>
    class CodeJamProblem
    {
        public int Number;
        long r;
        long t;

        /// <summary>
        /// Reads a test case
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public CodeJamProblem BuildProblem(CodeJamInput input)
        {
            string[] numbers = input.NextLine().Split(' ');
            this.r = long.Parse(numbers[0]);
            this.t = long.Parse(numbers[1]);
            return this;
        }

        /// <summary>
        /// Solves a the test case
        /// </summary>
        /// <returns></returns>
        public string GetSolution()
        {
            long n = 0;
            long increment = 1;
            bool incrementIncreasing = true;
            while (!(paintNeeded(n, r) <= t && paintNeeded(n+1, r) > t))
            {
                if (paintNeeded(n, r) < t)
                {
                    n += increment;
                }
                else
                {
                    n -= increment;
                    incrementIncreasing = false;
                }

                if (incrementIncreasing)
                {
                    increment *= 2;
                }
                else
                {
                    if (increment > 1){
                        increment /= 2;
                    }
                }
            }

            return "Case #" + Number + ": " + n;
        }

        public long paintNeeded(long n, long r)
        {
            return (2 * r * n) + (2 * n * n) - n;
        }
    }
}
