using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemC
{
    class program
    {
        public static int num, N, K, M;

        public static double Judge(int[] guessed, int[] numbers)
        {
            int hits = 0;
            int[] flags = new int[K]; //whether these numbers have been selected from the guessed numbers

            List<int> binarys = new List<int>();
            int z = -1;bool exit = false;
            while (!exit)
            {
                z++;
                if ((binarys.Count < N)&&(z <= 1))
                {
                    binarys.Add(z); z = -1;
                    if (binarys.Count == N)
                    {
                        int product = 1;
                        for (int i = 0; i < binarys.Count; i++)
                            if (binarys[i] == 1)
                                product *= guessed[i];

                        for (int i = 0; i < numbers.Length; i++)
                            if (numbers[i] == product)
                            {
                                flags[i] = 1;
                                hits++;
                            }
                    }
                }
                else                
                    if (binarys.Count == 0)
                        exit = true;
                    else
                    {
                        z = binarys[binarys.Count - 1]; binarys.RemoveAt(binarys.Count - 1);
                    }                
            }

            for (int i = 0; i < flags.Length; i++)
                if (flags[i] == 0)
                    return 0;

            return (double)hits;
        }

        public static void Main()
        {
            //List<string> input_lines = funcs.getInputDocs2(@"input.txt");
            List<string> input_lines = funcs.getInputDocs2(@"C-small-1-attempt0.in");
            //List<string> input_lines = funcs.getInputDocs2(@"A-large.in");
            
            int dmdm = int.Parse(input_lines[0]);
            string[] words = input_lines[1].Split(' ');
            num = int.Parse(words[0]); N = int.Parse(words[1]);
            M = int.Parse(words[2]); K = int.Parse(words[3]); //Upper Bound.

            List<string> outlines = new List<string>();
            outlines.Add("Case #1:");
            int lcount = 2;
            for (int samples = 0; samples < num; samples++)
            {
                string[] wt = input_lines[lcount].Split(' '); lcount++;
                int[] numbers = new int[K];
                List<int> results = new List<int>();
                double max = 0.0;

                for (int i = 0; i < wt.Length; i++) { numbers[i] = int.Parse(wt[i]); }

                int z = 1; bool exit = false;
                List<int> a = new List<int>();
                while (!exit)
                {
                    z++;
                    if ((a.Count<N)&&(z <= M))
                    {
                        a.Add(z); z = z - 1; //Increasing Order
                        if (a.Count == N)
                        {
                            double pb = Judge(a.ToArray(), numbers);
                            if (pb > max)
                            {
                                max = pb;
                                results = new List<int>();
                                for (int ppp = 0; ppp < a.Count; ppp++) results.Add(a[ppp]);
                            }
                        }
                    }
                    else
                    {
                        if (a.Count == 0)
                            exit = true;
                        else
                        {
                            z = a[a.Count - 1]; a.RemoveAt(a.Count - 1);
                        }
                    }
                }
                string outline = "";
                for (int i = 0; i < results.Count; i++)
                {
                    outline += results[i];
                    Console.Write(results[i]);
                }
                outlines.Add(outline);
                Console.WriteLine();
            }
            funcs.WriteLines(@"C-output.txt", outlines);
            Console.Read();
            Console.Read();
        }
    }
}
