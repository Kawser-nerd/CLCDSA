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

                    int c = int.Parse(inputs[0]);
                    int j = int.Parse(inputs[1]);

                    int exchanges = 2;

                    if (c + j > 0)
                    {
                        int[] s = new int[c + j];
                        int[] e = new int[c + j];

                        for (int m = 0; m < c + j; m++)
                        {
                            input = objInputFile.ReadLine().Trim();
                            inputs = input.Split();

                            s[m] = int.Parse(inputs[0]);
                            e[m] = int.Parse(inputs[1]);
                        }

                        if (c == 2 || j == 2)
                        {
                            Array.Sort(s, e);

                            if ((s[1] - e[0] < 720) && (e[1] - s[0] > 720))
                            {
                                exchanges = 4;
                            }
                        }
                    }

                    string output = "Case #" + i + ": " + exchanges;
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
