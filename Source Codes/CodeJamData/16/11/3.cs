using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;
using System.Numerics;
using System.Threading;
using GoogleCodeJamPractice.Library.Algorithms;
using GoogleCodeJamPractice.Library.Math;

namespace GoogleCodeJamPractice
{
    /// <summary>
    /// Reads a tipical Input for Google Code Jam's Problems, started by a line containing T, followed by T
    /// test cases
    /// </summary>
    class CodeJamInput
    {
        StreamReader reader = File.OpenText(@"i:\users\cecilia\documents\visual studio 2010\Projects\GoogleCodeJamPractice\GoogleCodeJamPractice\input.in");

        public CodeJamProblem[] problems;

        public string NextLine()
        {
            return reader.ReadLine();
        }

        public CodeJamInput()
        {
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
        static string outputPath = @"i:\users\cecilia\documents\visual studio 2010\Projects\GoogleCodeJamPractice\GoogleCodeJamPractice\output.out";

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
        public string S;

        /// <summary>
        /// Reads a test case and initializes the class' variables
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public CodeJamProblem BuildProblem(CodeJamInput input)
        {
            S = input.NextLine();

            return this;
        }

        /// <summary>
        /// Solves a test case from the variables
        /// </summary>
        /// <returns></returns>
        public string GetSolution()
        {
            string solution = "";

            foreach (char c in S)
            {
                if (solution.Length == 0 || solution[0] > c)
                {
                    solution = solution + c;
                } else
                {
                    solution = c + solution;
                }
            }

            return "Case #"+Number+": " + solution;
        }
    }
}
