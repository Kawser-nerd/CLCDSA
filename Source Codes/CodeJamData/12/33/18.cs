using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CodeJam
{
    class R1P9
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
            int M = int.Parse(ss[1]);

            ss = input.ReadLine().Split(' '); // 2 * N integers a1, A1, a2, A2, ..., aN, AN
            long[] a = new long[N]; //number
            long[] A = new long[N]; //type

            for (int i = 0, j=0; j<N && i < ss.Length; j++, i+=2)
            {
                a[j] = long.Parse(ss[i]);
                A[j] = long.Parse(ss[i + 1]);
            }

            ss = input.ReadLine().Split(' '); // 2 * M integers b1, B1, b2, B2, ..., bM, BM
            long[] b = new long[M];
            long[] B = new long[M];

            for (int i = 0, j = 0; j < M && i < ss.Length; j++, i += 2)
            {
                b[j] = long.Parse(ss[i]);
                B[j] = long.Parse(ss[i + 1]);
            }

            /*foreach(int ai in a) Console.Write(ai + " ");
            Console.WriteLine();
            foreach (int ai in A) Console.Write(ai + " ");
            Console.WriteLine();
            foreach (int ai in b) Console.Write(ai + " ");
            Console.WriteLine();
            foreach (int ai in B) Console.Write(ai + " ");
            Console.WriteLine();
            */
            long max = findMax(a, A, b, B, 0, 0, 0);


            /*int x = 0;
            for (int i = 0; i < N; i++)
            {
                x += int.Parse(ss[i + 1]);
                if (debug) console.Write(ss[i + 1] + " ");
            }*/
            if (debug) console.WriteLine();

            //result.Append(x);
            return max.ToString();
        }


        string getspaces(int p)
        {
            StringBuilder b = new StringBuilder();
            while (p-- != 0)
            {
                b.Append("  ");
                
            }
            return b.ToString();
        }

        long[] deepcopy(long[] a)
        {
            long[] b = new long[a.Length];
            for (long i = 0; i < b.Length; i++)
                b[i] = a[i];
            return b;
        }

        private long findMax(long[] countA, long[] typeA, long[] countB, long[] typeB, long a, long b, long pad)
        {

            countA = deepcopy(countA);
            countB = deepcopy(countB);

            long max = 0;

            if (a > typeA.Length -1)
                return 0;

            if(b > typeB.Length - 1)
                return 0;

            if (typeA[a] == typeB[b])
            {

                long seek = countA[a] <= countB[b] ? countA[a] : countB[b];
                max += seek;
                //Console.WriteLine(getspaces(pad) + "Matching at {0} and {1} for type {2} with value: {3}", a + 1, b + 1, typeA[a], seek);
                countA[a] -= seek;

                countB[b] -= seek;

                //if (countA[a] == 0)
                    //a++;
                //if (countA[b] == 0)
                    //b++;
            }
            //else
            //{
            long max1 = findMax(countA, typeA, countB, typeB, a + 1, b, pad + 1);
            long max2 = findMax(countA, typeA, countB, typeB, a, b + 1, pad + 1);
                max += max1 > max2 ? max1 : max2;

            //}


            return max;
        }




        public static void Main()
        {
            int n = int.Parse(input.ReadLine());
            for (int i = 0; i < n; i++)
            {
                console.WriteLine("Case #{0}: {1}", i + 1, new R1P9().solve());
            }
            console.Flush();
            //Console.ReadKey();
        }


    }
}
