using System;
using System.IO;

namespace Candy_Splitting
{
    internal class Program
    {
        private static void Main(string[] args)
        {

            string filename = @"C-large.in.txt";

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
            
            int N = int.Parse(reader.ReadLine());
            string[] s = reader.ReadLine().Split(' ');

            int xor = 0;
            int min = int.MaxValue;
            int sum = 0;
            for(int i=0; i<N; i++)
            {
                int p = int.Parse(s[i]);
                xor ^= p;
                sum += p;
                if (min > p)
                    min = p;
            }

            if (xor == 0)
            {
                Console.WriteLine("Case #{0}: {1}", C, sum-min);
                writer.WriteLine("Case #{0}: {1}", C, sum - min);
            }
            else
            {
                Console.WriteLine("Case #{0}: NO", C);
                writer.WriteLine("Case #{0}: NO", C);
            }
            
        }
    }
}