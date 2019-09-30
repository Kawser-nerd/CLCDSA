using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CodeJam
{
    class R2P2
    {
        private const string fileIn = @"C:\Users\aghaffar\Documents\Visual Studio 2010\Projects\Challenges\CodeJam\CodeJam\bin\Debug\input.in";
        private const string fileOut = @"C:\Users\aghaffar\Documents\Visual Studio 2010\Projects\Challenges\CodeJam\CodeJam\bin\Debug\output.txt";
        private static TextReader input = File.OpenText(fileIn);
        private static TextWriter console = File.CreateText(fileOut);
        //private static TextWriter console = Console.Out;

        public string solve()
        {
            bool debug = false;
            StringBuilder result = new StringBuilder(); ;

            string[] ss = input.ReadLine().Split(' ');

            int N = int.Parse(ss[0]);
            int W = int.Parse(ss[1]);
            int L = int.Parse(ss[2]);

            int[] R  = new int[N];
            ss = input.ReadLine().Split(' ');
            for (int i = 0; i < N; i++)
            {
                R[i] = int.Parse(ss[i]);
                if (debug) console.Write(" r:" + R[i]);
            }
            if (debug) console.WriteLine();

            //Array.Sort(R);

            //R = fourQuaderentSort(R).ToArray();

            foreach (int r in R)
            {
                if (debug) console.Write(" r:" + r);
            }
            if (debug) console.WriteLine();

            int maxW = 0;
            int index = 0;
            List<Pair> pairs = new List<Pair>();
            for (int w = 0; w < W; ) 
            {
                List<int> hr = new List<int>();
                for (int l = 0; l < L; )
                {
                    if (l != 0)
                    {
                        l += R[index];
                        if (l > L) continue;
                    }
                    /*if (debug)
                        console.WriteLine("{0} person at {1}, {2} ", index, w, l);
                    else
                        result.Append("" + w + " " +l + " ");*/
                    hr.Add(l);
                    l += R[index];
                    if (maxW < R[index])
                        maxW = R[index];
                    index++;
                    if (index == N) 
                    {
                        l = 0;
                        break; 
                    }
                    
                }

                if (w == 0)
                {
                    foreach (int k in hr)
                    {
                        pairs.Add(new Pair(0, k));
                    }
                }
                else
                {
                    w += maxW;
                    foreach (int k in hr)
                    {
                        pairs.Add(new Pair(w, k));
                    }

                }

                w += maxW;
                maxW = 0;
                if (index == N) break;

            }

            foreach (Pair p in pairs)
            {
                result.Append(p.i + " " + p.j + " ");
            }

            //result.Append(x);
            return result.ToString();
        }
        class Pair
        {
            public int i;
            public int j;

            public Pair(int p, int k)
            {
                // TODO: Complete member initialization
                i = p;
                j = k;
            }
        }

        private List<int> fourQuaderentSort(int[] R)
        {
            List<int> R1 = new List<int>();
            List<int> R2 = new List<int>();
            List<int> R3 = new List<int>();
            List<int> R4 = new List<int>();

            for (int i = 0; i < R.Length; i++)
            {
                if (i % 4 == 0)
                    R1.Add(R[i]);
                else if (i % 4 == 1)
                    R2.Add(R[i]);
                else if (i % 4 == 2)
                    R3.Add(R[i]);
                else if (i % 4 == 3)
                    R4.Add(R[i]);
            }

            R1.AddRange(R2);
            R1.AddRange(R3);
            R1.AddRange(R4);

            return R1;
        }

        public static void Main()
        {
            int n = int.Parse(input.ReadLine());
            for (int i = 0; i < n; i++)
            {
                console.WriteLine("Case #{0}: {1}", i + 1, new R2P2().solve());
            }
            console.Flush();
            Console.ReadKey();
        }


    }
}
