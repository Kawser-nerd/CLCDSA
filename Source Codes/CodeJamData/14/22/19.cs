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

                    int a = int.Parse(inputs[0]);
                    int b = int.Parse(inputs[1]);
                    int k = int.Parse(inputs[2]);                   

                    int total = 0;
                    for (int l = 0; l < a; l++)
                    {
                        for (int j = 0; j < b; j++)
                        {
                            int r = l & j;
                            if (r < k)
                            {
                                total++;
                            }
                        }
                    }

                    string output = "Case #" + i + ": " + total;
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
