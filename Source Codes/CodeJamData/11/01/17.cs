using System;
using System.IO;

namespace Bot_Trust
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"A-large.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (StreamReader reader = new StreamReader(filename))
            {
                using (StreamWriter writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');
            int N = int.Parse(s[0]);

            int swap = 0;
            int index = 1;

            int posO = 1;
            int posB = 1;

            int swapO = 0;
            int swapB = 0;

            for (int i = 0; i < N; i++ )
            {
                int p = int.Parse(s[index + 1]);
                if (s[index] == "B")
                {
                    OneStep(ref posB, p, ref  swapB, swap);
                    swap = swapB;
                }
                else
                {
                    OneStep(ref posO, p, ref  swapO, swap);
                    swap = swapO;
                }
                index += 2;
            }

                Console.WriteLine("Case #{0}: {1}", C, swap);
            writer.WriteLine("Case #{0}: {1}", C, swap);
        }

        private static void OneStep(ref int pos, int p, ref int swap, int swap_curr)
        {
            int move = Math.Abs(p - pos);
            move++;

            pos = p;

            int delta = swap_curr - swap;

            if (move <= delta)
            {
                swap = swap_curr + 1;
            }
            else
            {
                swap = swap_curr + (move - delta);
            }
        }
    }
}