using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace C
{
    class Program
    {

        static bool findSubsets(int[] set, out int[] subset1, out int[] subset2)
        {
            // brute force: look at all subsets of "set"
            Dictionary<int, int[]> sumsFound = new Dictionary<int, int[]>();
            int max = (int)Math.Pow(2, set.Length);

            for (int i = 1; i < max; i++)
            {
                // create subset
                List<int> subsetList = new List<int>();
                for (int j = 0; j < set.Length; j++)
                {
                    int bitMask = (int)Math.Pow(2, j);
                    if ((i & bitMask) > 0)
                        subsetList.Add(set[j]);
                }

                int sum = subsetList.Sum();
                int[] subset = subsetList.ToArray();

                if (sumsFound.ContainsKey(sum))
                {
                    subset1 = subset;
                    subset2 = sumsFound[sum];
                    return true;
                }

                sumsFound[sum] = subset;


            }

            subset1 = null;
            subset2 = null;


            return false;
        }



        static void Main(string[] args)
        {

            // remove to run from command line
            args = new string[] { "", "input.txt", "output.txt" };
            // --

            if (args.Length < 3)
            {
                Console.WriteLine("Provide input and output file names as parameter.");
                return;
            }

            // first param = name of input file
            string inputFileName = args[1];
            string outputFileName = args[2];

            if (!File.Exists(inputFileName))
            {
                Console.WriteLine("File not found: {0}", inputFileName);
                return;
            }

            if (File.Exists(outputFileName))
            {
                File.Delete(outputFileName);
            }


            using (StreamReader sr = File.OpenText(inputFileName))
            {
                using (StreamWriter sw = File.CreateText(outputFileName))
                {
                    string testCasesStr = sr.ReadLine();
                    int T = 0;
                    int.TryParse(testCasesStr, out T);

                    Console.WriteLine("T = {0}", T);

                    for (int i = 1; i <= T; i++)
                    {
                        Console.WriteLine("Looking at Case #{0}...", i);
                        string str = sr.ReadLine();
                        Console.WriteLine(str);

                        string[] valuesStr = str.Split(' ');
                        int N = int.Parse(valuesStr[0]);

                        int[] set = new int[N];
                        for (int j = 0; j < N; j++)
                        {
                            set[j] = int.Parse(valuesStr[j + 1]);
                        }

                        // find 2 subsets with same sum
                        int[] subset1;
                        int[] subset2;
                        bool found = findSubsets(set, out subset1, out subset2);
                        
                        string result = string.Format("Case #{0}:", i);
                        Console.WriteLine(result);
                        sw.WriteLine(result);

                        if (!found)
                        {
                            string result2 = "Impossible";
                            Console.WriteLine(result2);
                            sw.WriteLine(result2);
                        }
                        else
                        {
                            string result2 = string.Join(" ", subset1);
                            string result3 = string.Join(" ", subset2);
                            Console.WriteLine(result2);
                            sw.WriteLine(result2);
                            Console.WriteLine(result3);
                            sw.WriteLine(result3);
                        }

                    }

                    sw.Close();
                }


                sr.Close();
            }

            Console.WriteLine("Done!");
            Console.ReadKey();

        }
    }
}
