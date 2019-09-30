///////////////////////////////////////////////////////////////////////
/// <summary>
/// Google Code Jam 2011 Round 1B Problem A
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
            string inputFileName = "A-Large.in";
            string outputFileName = "A-Large.out";
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
        /// Problem solution code. -- Google Code Jam 2011 Round 1B -- Problem A
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

                string strN = input.Lines[currentLine++];
                int n = int.Parse(strN);
                string[] team = new string[n];
                int[] nbrPlayed = new int[n];
                int[] nbrWin = new int[n];
                double[] wp = new double[n];
                for (int i = 0; i < n; i++)
                {
                    team[i] = input.Lines[currentLine++];
                    for (int j = 0; j < n; j++)
                    {
                        char c = team[i][j];
                        if (c == '1')
                        {
                            nbrPlayed[i]++;
                            nbrWin[i]++;
                        }
                        if (c == '0')
                        {
                            nbrPlayed[i]++;
                        }
                    }
                }
                double[] rpi = new double[n];
                for (int i = 0; i < n; i++)
                {
                    wp[i] = (double)nbrWin[i] / (double)nbrPlayed[i];
                }
                double[] owp = new double[n];
                for (int i = 0; i < n; i++)
                {
                    owp[i] = 0;
                    rpi[i] = 0.25 * wp[i];
                    if (nbrPlayed[i] > 1)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            char c = team[i][j];
                            if (c != '.' && i != j)
                            {
                                if ( c == '1')
                                    owp[i] += (double)nbrWin[j] / ((double)nbrPlayed[j] - 1);
                                if (c == '0')
                                    owp[i] += ((double)nbrWin[j] - 1) / ((double)nbrPlayed[j] - 1);
                            }
                        }
                        owp[i] /= (double)nbrPlayed[i];
                        rpi[i] += owp[i] * 0.5;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    double oowp = 0;
                    if (nbrPlayed[i] > 1)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            char c = team[i][j];
                            if (c != '.' && i != j)
                            {
                                oowp += owp[j];
                            }
                        }
                    }
                    oowp /= ((double)nbrPlayed[i]);
                    rpi[i] += oowp * 0.25;
                }
                output.AppendFormat("Case #{0}:", currentCase);
                output.AppendLine();
                for (int i = 0; i < n; i++)
                {
                    output.AppendLine(rpi[i].ToString());
                }
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

