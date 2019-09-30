using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class Program
    {
        static Random r = new Random();

        static void DoBad(int[] a)
        {
            for(int k = 0; k < 1000; ++k)
            {
                a[k] = k;
            }
            for(int k = 0; k < 1000; ++k)
            {
                int p = r.Next(1000);
                int temp = a[p];
                a[p] = a[k];
                a[k] = temp;
            }
        }


        static void DoGood(int[] a)
        {
            for (int k = 0; k < 1000; ++k)
            {
                a[k] = k;
            }
            for (int k = 0; k < 1000; ++k)
            {
                int p = r.Next(1000 - k) + k;
                int temp = a[p];
                a[p] = a[k];
                a[k] = temp;
            }
        }

        static void Main2(string[] args)
        {

            var root = @"D:\gcj\p3\";

            int[] a = new int[1000];

            int[,] g = new int[1000, 1000];
            int[,] b = new int[1000, 1000];


/*
            for (int i = 0; i < 1000000; ++i)
            {
                if (i % 10000 == 0)
                {
                    Console.WriteLine("it " + i);
                }
                DoGood(a);
                for (int j = 0; j < 1000; ++j)
                {
                    g[a[j], j]++;
                }


                DoBad(a);
                for (int j = 0; j < 1000; ++j)
                {
                    b[a[j], j]++;
                }
            }

            StreamWriter output = new StreamWriter(root + "input.txt");
            for (int i = 0; i < 1000; ++i)
            {
                for (int j = 0; j < 1000; ++j)
                {
                    output.Write(g[i, j] + " ");
                }
                output.Write("\n");
            }


            for (int i = 0; i < 1000; ++i)
            {
                for (int j = 0; j < 1000; ++j)
                {
                    output.Write(b[i, j] + " ");
                }
                output.Write("\n");
            }


            output.Close();*/
            Console.WriteLine("Gen done, starting test output");

            StreamWriter output2 = new StreamWriter(root + "small.txt");
            output2.WriteLine("120");
            for (int i = 0; i < 120; ++i)
            {
                output2.WriteLine("1000");
                if (i < 60)
                {
                    DoGood(a);
                }
                else
                {
                    DoBad(a);
                }

                for (int j = 0; j < 1000; ++j)
                {
                    output2.WriteLine(a[j]);
                }
            }
            output2.Close();



        }


        static void Main(string[] args)
        {

               var root = @"D:\gcj\p3\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            
            int[] data = input.SelectMany(x => x.Split(' ').Select(y => Int32.Parse(y))).ToArray();
            IEnumerator<int> scanner = data.AsEnumerable<int>().GetEnumerator();
            scanner.MoveNext();
            int numCases = scanner.Current;
            for (int nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                int N = scanner.Current;


                int[] a = new int[1000];
                for (int i = 0; i < N; ++i)
                {
                    scanner.MoveNext();
                    a[i] = scanner.Current;
                }


            int[,] g = new int[1000, 1000];
            int[,] b = new int[1000, 1000];


                string[] input2 = System.IO.File.ReadAllLines(root + "input.txt");
                int[] data2 = input2.SelectMany(x => x.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries).Select(y => Int32.Parse(y))).ToArray();
                IEnumerator<int> scanner2 = data2.AsEnumerable<int>().GetEnumerator();


                for (int i = 0; i < 1000; ++i)
                {
                    for (int j = 0; j < 1000; ++j)
                    {
                        scanner2.MoveNext();
                        g[i, j] = scanner2.Current;
                    }
                }


                for (int i = 0; i < 1000; ++i)
                {
                    for (int j = 0; j < 1000; ++j)
                    {
                        scanner2.MoveNext();
                        b[i, j] = scanner2.Current;
                    }
                }


                int bc = 0;
                int gc = 0;

                int diff = 0;
                int maxDiff = -100000000;
                int minDiff = 10000000;
                for (int i = 0; i < 1000; ++i)
                {
                    diff += g[a[i], i] - b[a[i], i];
                    maxDiff = Math.Max(maxDiff, g[a[i], i] - b[a[i], i]);
                    minDiff = Math.Min(minDiff, g[a[i], i] - b[a[i], i]);
                }

                Console.WriteLine(diff + " " + maxDiff + " " + minDiff);
                output.WriteLine("Case #{0}: {1}", nc + 1, diff > -7500 ? "GOOD" : "BAD");
                Console.WriteLine("Case #{0}: {1}", nc + 1, diff > -7500 ? "GOOD" : "BAD");
            }

            output.Close();

        }
    }
}
