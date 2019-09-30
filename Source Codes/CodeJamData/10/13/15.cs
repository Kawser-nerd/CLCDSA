using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace Practice
{

    class Program
    {
        static string inputFile, outputFile;

        static void getIOFileNames(string[] args)
        {
            Console.WriteLine();
            // Get input/output file names
            if (args != null && args.Length > 1 && args[0] != null)
            {
                inputFile = args[0];
                Console.WriteLine("We will get input from " + inputFile);
            }
            else
            {
                Console.Write("Name of Input File: ");
                inputFile = Console.ReadLine();
            }
            if (args != null & args.Length > 1 && args[1] != null)
            {
                outputFile = args[1];
                Console.WriteLine("We will get output from " + outputFile);
            }
            else
            {
                Console.Write("Name of Output File: ");
                outputFile = Console.ReadLine();
            }
        }

        static void Main(string[] args)
        {
            getIOFileNames(args);

            // Prepare output file
            Console.WriteLine();
            Console.WriteLine("Prepare to write data to " + outputFile);
            StreamWriter sw = File.CreateText(outputFile);

            // Process file
            Console.WriteLine("Processing data from " + inputFile);

            StreamReader sr = File.OpenText(inputFile);
            string s = sr.ReadLine();
            if (s == null)
            {
                throw new Exception("invalid input file");
            }
            long NumTestCases = Convert.ToInt64(s);
            if (NumTestCases < 1)
            {
                throw new Exception("Invalid number of test cases: " + NumTestCases.ToString());
            }
            Console.WriteLine();
            Console.WriteLine("--------------------");
            Console.WriteLine();
            for (int i = 1; i <= NumTestCases; i++)
            {
                string[] input1 = sr.ReadLine().Split(new char[] {' '});
                int A1 = Convert.ToInt32(input1[0]);
                int A2 = Convert.ToInt32(input1[1]);
                int B1 = Convert.ToInt32(input1[2]);
                int B2 = Convert.ToInt32(input1[3]);

                string output = ProcessTestCase(i, A1, A2, B1, B2);
                sw.WriteLine(output);
            }

            // Cleanup
            sr.Close();
            sw.Close();
            Console.WriteLine();
        }

        static string ProcessTestCase(int CaseNo, int A1, int A2, int B1, int B2)
        {
            int numPositions = 0;

            for (int i = A1; i <= A2; i++)
            {
                for (int j = B1; j <= B2; j++)
                {
                    if ((i == 2) && (j == 1))
                    {
                        bool test = true;
                    }

                    if (CanForceWin(i, j, false))
                    {
//                        Console.WriteLine(i.ToString() + ", " + j.ToString() + " : " + "Yes");
                        numPositions++;
                    }
                    else
                    {
//                        Console.WriteLine(i.ToString() + ", " + j.ToString() + " : " + "No");
                    }
                }
            }

            string output = "Case #" + CaseNo.ToString() + ": " + numPositions.ToString();                        
            Console.WriteLine("Output: " + output);
            Console.WriteLine();
            return output;
        }

        static bool CanForceWin(int small, int big, bool reverse)
        {
            if (small == big)
            {
                return reverse;
            }

            int numMult = 0;
            if (small > big)
            {
                int temp = small;
                small = big;
                big = temp;
            }

            int tempVal = big;
            while (tempVal - small > 0)
            {
                tempVal = tempVal - small;
                numMult++;
            }

            if (numMult > 1)
                return !reverse;
            else
                return CanForceWin(tempVal, small, !reverse);

        }

    }
}
