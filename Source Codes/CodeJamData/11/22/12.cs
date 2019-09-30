///////////////////////////////////////////////////////////////////////
/// <summary>
/// Google Code Jam 2011 Round 1B Problem B
/// Christian Leclerc's submission
/// </summary>
/// <param name="args">First Parameter: Input file, second parameter: Output file.</param>
///////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;

using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        ///////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Main function. Should not have to change between problems.
        /// </summary>
        /// <param name="args">First Parameter: Input file, second parameter: Output file.</param>
        ///////////////////////////////////////////////////////////////////////
        public static void Main(string[] args)
        {
            string inputFileName = "B-Large.in";
            string outputFileName = "B-Large.out";
            if (args.GetLength(0) > 0)
                inputFileName = args[0];
            string result = Solve(new InputFile(inputFileName));
            if (args.GetLength(0) > 1)
                outputFileName = args[1];
            System.IO.StreamWriter textWriter = new System.IO.StreamWriter(outputFileName);
            textWriter.Write(result);
            textWriter.Close();
        }


        ///////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Problem solution code. -- Google Code Jam 2011 Round 1B -- Problem B
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        ///////////////////////////////////////////////////////////////////////
        private static string Solve(InputFile input)
        {
            int currentLine = 0;
            StringBuilder output = new StringBuilder();
            for (int currentCase = 1; currentCase <= input.NumberOfCases; currentCase++)
            {

                string[] cd = input.Lines[currentLine++].Split(' ');
                int c = int.Parse(cd[0]);
                double d = int.Parse(cd[1]);
                int[] p = new int[c];
                double[] v = new double[c];
                for (int i = 0; i < c; i++)
                {
                    string[] pv = input.Lines[currentLine++].Split(' ');
                    p[i] = int.Parse(pv[0]);
                    v[i] = int.Parse(pv[1]);
                }
                double time = -d/2;
                double worst = 0;
                int lastp = p[0];
                for (int i = 0; i < c; i++)
                {
                    time -= (double)(p[i] - lastp) / 2;
                    lastp = p[i];
                    if (time <= -d/2)
                    {
                        time = ((v[i] - 1) * d) / 2;
                    }
                    else
                    {
                        time += ((v[i]) * d) / 2;
                    }
                    if (worst < time)
                        worst = time;
                }
                output.AppendFormat("Case #{0}: {1}", currentCase, worst);
                output.AppendLine();
            }
            return output.ToString();
        }
    }


    ///////////////////////////////////////////////////////////////////////
    /// <summary>
    /// Basic parser for the input file.
    /// </summary>
    ///////////////////////////////////////////////////////////////////////
    class InputFile
    {
        #region Private Members

        private ArrayList lines = new ArrayList();
        private int numCases;


        #endregion

        #region Public Properties

        ///////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Gets an array of lines from the file.
        /// </summary>
        ///////////////////////////////////////////////////////////////////////
        public string[] Lines
        {
            get { return (string[])lines.ToArray(typeof(string)); }
        }


        ///////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Gets the number of cases (N) in the input file (First line of the file)
        /// </summary>
        ///////////////////////////////////////////////////////////////////////
        public int NumberOfCases
        {
            get { return numCases; }
        }
        #endregion


        #region Constructors

        ///////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="filename"></param>
        ///////////////////////////////////////////////////////////////////////
        public InputFile(string filename)
        {
            TextReader textReader = new StreamReader(filename);
            numCases = int.Parse(textReader.ReadLine());
            string line = textReader.ReadLine();
            while (line != null)
            {
                lines.Add(line);
                line = textReader.ReadLine();
            }
            textReader.Close();
        }

        #endregion

        #region Public Methods

        #endregion
    }
}

