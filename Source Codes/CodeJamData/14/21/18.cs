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
                    int n = int.Parse(input);

                    List<char>[] charTable = new List<char>[n];
                    List<int>[] countTable = new List<int>[n];

                    for (int j = 0; j < n; j++)
                    {
                        input = objInputFile.ReadLine().Trim();

                        charTable[j] = new List<char>();
                        countTable[j] = new List<int>();

                        int index = -1;
                        for (int k = 0; k < input.Length; k++)
                        {
                            if ((index == -1) || (charTable[j][index] != input[k]))
                            {
                                charTable[j].Add(input[k]);
                                countTable[j].Add(1);
                                index++;
                            }
                            else
                            {
                                countTable[j][index]++;
                            }
                        }
                    }

                    bool isPossible = true;
                    int totalMovesCiel = 0;
                    int totalMovesFloor = 0;

                    int chars = charTable[0].Count;
                    for (int j = 1; j < n; j++)
                    {
                        if (charTable[j].Count != chars)
                        {
                            isPossible = false;
                            break;
                        }
                    }

                    if (isPossible)
                    {
                        for (int j = 0; j < chars; j++)
                        {
                            int total = countTable[0][j];
                            char c = charTable[0][j];

                            for (int k = 1; k < n; k++)
                            {
                                if (charTable[k][j] == c)
                                {
                                    total += countTable[k][j];
                                }
                                else
                                {
                                    isPossible = false;
                                    break;
                                }
                            }

                            if (!isPossible)
                            {
                                break;
                            }

                            int avgCiel = (int)Math.Ceiling((float)total/n);
                            int avgFloor = (int)Math.Floor((float)total / n);

                            for (int k = 0; k < n; k++)
                            {
                                totalMovesCiel += Math.Abs(avgCiel - countTable[k][j]);
                                totalMovesFloor += Math.Abs(avgFloor - countTable[k][j]);
                            }
                        }                        
                    }

                    string output = "Case #" + i + ": " + (isPossible ? (totalMovesCiel < totalMovesFloor ?  totalMovesCiel.ToString() : totalMovesFloor.ToString()) : "Fegla Won");
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
    }
}
