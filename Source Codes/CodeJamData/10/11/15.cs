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
                int N = Convert.ToInt32(input1[0]);
                int K = Convert.ToInt32(input1[1]);
                sw.WriteLine("Case " + i.ToString());
                sw.WriteLine("N=" + N.ToString() + ", K=" + K.ToString());

                // Get the test case data as an array of strings
                string[] thisCase = new string[N];
                for (int j = 1; j <= N; j++)
                {
                    thisCase[j - 1] = sr.ReadLine();
                    sw.WriteLine(thisCase[j - 1]);
                }

                string output = ProcessTestCase(i, N, K, thisCase);
                sw.WriteLine(output);
            }

            // Cleanup
            sr.Close();
            sw.Close();
            Console.WriteLine();
        }

        static string ProcessTestCase(int CaseNo, int N, int K, string[] data)
        {
            string[] BeforeGravity = data;

            // Holds horizontal possibilites for winning
            string[] AfterGravity = new string[N];
            // Holds vertical possibilites for winning
            char[,] Vertical = new char[N,N];
            string blankStr = "";
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    Vertical[i,j] = '.';
                }
            }

            // Has either team won yet?
            bool Rwon = false;
            bool Bwon = false;

            // Put together a winning string
            string Rwins = blankStr.PadRight(K, 'R');
            string Bwins = blankStr.PadRight(K, 'B');

            // Make gravity happen
            for(int i = 0; i < N; i++)
            {
                String s = BeforeGravity[i];

                // remove all dots from the string
                while (s.IndexOf('.') != -1)
                {
                    s = s.Remove(s.IndexOf('.'), 1);
                }

                // add those dots back to the beginning of the string
                s = s.PadLeft(N, '.');

                AfterGravity[i] = s;

                // Go ahead and search for winners for the horizontal case
                if (AfterGravity[i].IndexOf(Rwins) != -1)
                {
                    Rwon = true;
                }
                if (AfterGravity[i].IndexOf(Bwins) != -1)
                {
                    Bwon = true;
                }

                // Build the Vertical lines
                for (int j = 0; j < N; j++)
                {
                    Vertical[j,i] = AfterGravity[i][j];
                }
            }

            for(int i = 0; i < N; i++)
            {
                char[] chars = new char[N];
                for(int j = 0; j < N; j++)
                {
                    chars[j] = Vertical[i, j];                    
                }

                string s = new string(chars);
                // Go ahead and search for winners for the horizontal case
                if (s.IndexOf(Rwins) != -1)
                {
                    Rwon = true;
                }
                if (s.IndexOf(Bwins) != -1)
                {
                    Bwon = true;
                }
            }

            // Diagonal transform in both directions at once
            for (int i = 1 - N; i < N; i++)
            {
                char[] chars = new char[N];
                char[] otherChars = new char[N];
                for (int j = 0; j < N; j++)
                {
                    if (((i + j) >= 0) && ((i + j) < N))
                    {
                        chars[j] = AfterGravity[i + j][j];
                        otherChars[j] = AfterGravity[i + j][N - 1 - j];
                    }
                    else
                    {
                        chars[j] = '.';
                    }
                }
                string s = new string(chars);
                string t = new string(otherChars);
                // Go ahead and search for winners for the horizontal case
                if ((s.IndexOf(Rwins) != -1) || (t.IndexOf(Rwins) != -1))
                {
                    Rwon = true;
                }
                if ((s.IndexOf(Bwins) != -1) || (t.IndexOf(Bwins) != -1))
                {
                    Bwon = true;
                }
            }

            string winStr = "Neither";
            if (Bwon && Rwon) { winStr = "Both"; }
            else if (Bwon) { winStr = "Blue"; }
            else if (Rwon) { winStr = "Red"; }

            string output = "Case #" + CaseNo.ToString() + ": " + winStr;                        
            Console.WriteLine("Output: " + output);
            Console.WriteLine();
            return output;
        }

    }
}
