using System;
using System.Collections.Generic;
using System.ComponentModel;
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
        public int N;
        public int[] Graph;

        /// <summary>
        /// Reads a test case and initializes the class' variables
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public CodeJamProblem BuildProblem(CodeJamInput input)
        {
            N = int.Parse(input.NextLine());

            Graph = input.NextLine().Split(' ').Select(i => int.Parse(i)-1).ToArray();

            return this;
        }

        /// <summary>
        /// Solves a test case from the variables
        /// </summary>
        /// <returns></returns>
        public string GetSolution()
        {
            bool[] mutuals = FindMutuals(Graph);

            int[] mutualsValues = new int[Graph.Length];

            for (int i = 0; i < Graph.Length; i++)
            {
                bool[] visited = new bool[Graph.Length];
                int count = 0;

                int j = i;
                while (!visited[j] && !mutuals[j])
                {
                    visited[j] = true;
                    j = Graph[j];
                    count++;
                }

                if (mutuals[j])
                    mutualsValues[j] = mutualsValues[j] > count ? mutualsValues[j] : count;
            }

            int cycle = FindBiggestCycleSize(Graph);

            int circleCount = mutuals.Count(b => b) + mutualsValues.Sum();
            int result = cycle > circleCount ? cycle : circleCount;

            return "Case #" + Number + ": " + result;
        }

        private int FindBiggestCycleSize(int[] graph)
        {
            int cyc = 0;

            for (int i = 0; i < graph.Length; i++)
            {
                bool[] visited = new bool[graph.Length];
                int count = 0;

                int j = i;
                while (!visited[j])
                {
                    visited[j] = true;
                    j = graph[j];
                    count++;
                }
                if (i == j)
                {
                    cyc = count > cyc ? count : cyc;
                }
            }

            return cyc;
        }

        private bool[] FindMutuals(int[] graph)
        {
            bool[] result = new bool[graph.Length];
            for (int i = 0; i < graph.Length; i++)
            {
                if (graph[graph[i]] == i)
                    result[i] = true;
            }

            return result;
        }

    }
}
