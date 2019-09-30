using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            if ((args.Length > 0) && (File.Exists(args[0]) == true))
            {
                Program objProgram = new Program();
                objProgram.PerformOperation(args[0]);
            }
            else
            {
                Console.WriteLine("ERROR! No file name given of the given file does not exist!");
            }
        }

        bool[,] flightPresent = null;
        int[] leastOrder = null;
        int[] zipCodes = null;

        public void PerformOperation(string fileName)
        {
            StreamReader objInputFile = new StreamReader(fileName);
            StreamWriter objOutputFile = new StreamWriter(Path.GetDirectoryName(fileName) + Path.DirectorySeparatorChar + Path.GetFileNameWithoutExtension(fileName) + ".out");

            try
            {
                // Getting the number of test cases
                string input = objInputFile.ReadLine().Trim();
                int numTestCases = int.Parse(input);

                for (int i = 1; i <= numTestCases; i++)
                {
                    input = objInputFile.ReadLine().Trim();
                    string[] inputs = input.Split();

                    int n = int.Parse(inputs[0]);
                    int m = int.Parse(inputs[1]);

                    zipCodes = new int[n];

                    for (int j = 0; j < n; j++)
                    {
                        input = objInputFile.ReadLine().Trim();
                        zipCodes[j] = int.Parse(input);
                    }

                    flightPresent = new bool[n, n];
                    leastOrder = null;

                    for (int j = 0; j < m; j++)
                    {
                        input = objInputFile.ReadLine().Trim();
                        inputs = input.Split();

                        int from = int.Parse(inputs[0]);
                        int to = int.Parse(inputs[1]);

                        flightPresent[from - 1, to - 1] = true;
                        flightPresent[to - 1, from - 1] = true;
                    }

                    int[] flightOrder = new int[n];

                    RecurseFlightOrder(flightOrder, n, 0);

                    StringBuilder leastOrderStr = new StringBuilder();
                    for (int j = 0; j < n; j++)
                    {
                        leastOrderStr.Append(zipCodes[leastOrder[j]]);
                    }

                    string output = "Case #" + i + ": " + leastOrderStr.ToString();
                    objOutputFile.WriteLine(output);

#if (DEBUG)
                    Console.WriteLine(output);
#endif
                }

                Console.WriteLine("Output file generated successfully!!");
            }
            finally
            {
                if (objInputFile != null)
                {
                    objInputFile.Close();
                }

                if (objOutputFile != null)
                {
                    objOutputFile.Close();
                }
            }
        }

        private void RecurseFlightOrder(int[] flightOrder, int n, int p)
        {
            if (p < n)
            {
                for (int i = 0; i < n; i++)
                {
                    bool added = false;
                    for (int j = 0; j < p; j++)
                    {
                        if (flightOrder[j] == i)
                        {
                            added = true;
                            break;
                        }
                    }

                    if (!added)
                    {
                        flightOrder[p] = i;
                        RecurseFlightOrder(flightOrder, n, p + 1); 
                    }
                }
            }
            else
            {
                Stack<int> flightStack = new Stack<int>();
                flightStack.Push(flightOrder[0]);

                int i;
                for (i = 1; i < n; i++)
                {
                    while (flightStack.Count > 0)
                    {
                        if (flightPresent[flightStack.Peek(), flightOrder[i]] == true)
                        {
                            flightStack.Push(flightOrder[i]);
                            break;
                        }
                        else
                        {
                            flightStack.Pop();
                        }
                    }

                    if (flightStack.Count <= 0)
                    {
                        break;
                    }
                }

                if (i == n)
                {
                    if (leastOrder == null)
                    {
                        leastOrder = new int[n];
                        Array.Copy(flightOrder, leastOrder, n);
                    }
                    else
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (zipCodes[flightOrder[j]] < zipCodes[leastOrder[j]])
                            {
                                Array.Copy(flightOrder, leastOrder, n);
                                break;
                            }
                            else if (zipCodes[flightOrder[j]] > zipCodes[leastOrder[j]])
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
