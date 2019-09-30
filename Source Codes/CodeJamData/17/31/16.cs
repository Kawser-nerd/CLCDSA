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
                    int k = int.Parse(inputs[1]);

                    int[] r = new int[n];
                    int[] h = new int[n];

                    for (int j = 0; j < n; j++)
                    {
                        input = objInputFile.ReadLine().Trim();
                        inputs = input.Split();

                        r[j] = int.Parse(inputs[0]);
                        h[j] = int.Parse(inputs[1]);
                    }

                    Array.Sort(r, h);

                    Array.Reverse(r);
                    Array.Reverse(h);

                    double max = 0;
                    for (int j = 0; j < (n - k + 1); j++)
                    {
                        long[] p = new long[n - j - 1];
                        for (int m = j + 1; m < n; m++)
                        {
                            p[m - j - 1] = ((long)r[m]) * ((long)h[m]); 
                        }

                        Array.Sort(p);
                        Array.Reverse(p);

                        double area = Math.PI * r[j] * r[j] + 2 * Math.PI * r[j] * h[j];
                        for (int m = 0; m < (k - 1); m++)
                        {
                            area += (2 * Math.PI * p[m]);
                        }

                        if (area > max)
                        {
                            max = area;
                        }
                    }

                    string output = "Case #" + i + ": " + max.ToString("F9");
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
