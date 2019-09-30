using System;

namespace ABC062B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int H = Int32.Parse(bufs[0]);
            int W = Int32.Parse(bufs[1]);

            string[] keep = new string[H];

            for (int i = 0; i < H; i++)
            {
                keep[i] = Console.ReadLine();
            }

            for (int i = 0; i < W + 2; i++)
            {
                Console.Write('#');
            }
            Console.WriteLine();

            for (int i = 0; i < H; i++)
            {
                Console.WriteLine("#{0}#", keep[i]);
            }

            for (int i = 0; i < W + 2; i++)
            {
                Console.Write('#');
            }
            Console.WriteLine();
        }
    }
}