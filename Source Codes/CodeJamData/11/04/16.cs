using System;
using System.IO;

namespace GoroSort
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"D-large.in.txt";

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

            int[] m = new int[N];
            for(int i=0; i<N; i++)
            {
                m[i] = int.Parse(s[i]);
            }

            int swap = 0;

            for (int i = 1; i <= N; i++)
            {
                int index = i-1;
                int count = 0;
                while(m[index] != -1)
                {
                    count++;
                    int ind = index;
                    index = m[index]-1;
                    m[ind] = -1;
                }
                if (count != 1)
                    swap += count;
            }

            Console.WriteLine("Case #{0}: {1}.000000", C, swap);
            writer.WriteLine("Case #{0}: {1}.000000", C, swap);
        }
    }
}