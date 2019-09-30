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
        long MaxEnergy, CurEnergy, R, N;
        long[] values;

        /// <summary>
        /// Reads a test case
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public CodeJamProblem BuildProblem(CodeJamInput input)
        {
            string[] numbers = input.NextLine().Split(' ');
            this.MaxEnergy = long.Parse(numbers[0]);
            CurEnergy = MaxEnergy;
            this.R = long.Parse(numbers[1]);
            this.N = long.Parse(numbers[2]);
            R = R > MaxEnergy ? MaxEnergy : R;
            numbers = input.NextLine().Split(' ');
            values = new long[N];
            for (int i = 0; i < N; i++)
            {
                values[i] = long.Parse(numbers[i]);
            }

            return this;
        }

        /// <summary>
        /// Solves a the test case
        /// </summary>
        /// <returns></returns>
        public string GetSolution()
        {
            long gain = 0;
            for (int i = 0; i < N; i++)
            {
                int j;
                for (j = i+1; j < N; j++)
                {
                    if (values[i] < values[j])
                        break;
                }
                if (MaxEnergy / R < j - i || j == N)
                {
                    //Waste everything
                    gain += CurEnergy * values[i];
                    CurEnergy = R;
                }
                else 
                {
                    if (CurEnergy - (MaxEnergy - (j - i) * R) > 0){
                        gain += ((CurEnergy - (MaxEnergy - (j - i) * R)) * values[i]);
                        CurEnergy = (MaxEnergy - (j - i) * R) + R;
                    } else {
                        CurEnergy += R;
                    }
                }
            }

            return "Case #" + Number + ": " + gain;
        }
    }
}
