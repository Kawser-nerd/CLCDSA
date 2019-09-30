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
                    string[] inputs = input.Split();

                    int n = int.Parse(inputs[0]);

                    input = objInputFile.ReadLine().Trim();
                    double u = Double.Parse(input);

                    input = objInputFile.ReadLine().Trim();
                    double[] p = Array.ConvertAll(input.Split(), Double.Parse);

                    Array.Sort(p);

                    for (int j = 1; j < n; j++)
                    {
                        double d = p[j] - p[j - 1];

                        if (u >= (d * j))
                        {
                            for (int m = 0; m < j; m++)
                            {
                                p[m] += d;
                                u -= d;
                            }
                        }
                        else
                        {
                            double d1 = u / j;
                            for (int m = 0; m < j; m++)
                            {
                                p[m] += d1;
                            }
                            u = 0;
                        }

                        if (u <= 0)
                        {
                            break;
                        }
                    }

                    if (u > 0 && p[n - 1] < 1)
                    {
                        double d = 1 - p[n - 1];

                        if (u >= (d * n))
                        {
                            for (int m = 0; m < n; m++)
                            {
                                p[m] += d;
                                u -= d;
                            }
                        }
                        else
                        {
                            double d1 = u / n;
                            for (int m = 0; m < n; m++)
                            {
                                p[m] += d1;
                            }
                            u = 0;
                        }
                    }

                    double totalP = 1;
                    for (int j = 0; j < n; j++)
                    {
                        totalP *= p[j];
                    }

                    string output = "Case #" + i + ": " + totalP.ToString("F8");
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
