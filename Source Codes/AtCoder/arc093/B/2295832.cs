using System;

namespace d
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split();
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);

            char[][] map = new char[100][];

            for (int i = 0; i < 100; i++)
            {
                map[i] = new char[100];
                for (int j = 0; j < 100; j++)
                {
                    map[i][j] = i < 50 ? '.' : '#';
                }
            }

            for (int i = 0; i < b - 1; i++)
            {
                map[2 * (i / 50)][2 * (i % 50)] = '#';
            }

            for (int i = 0; i < a - 1; i++)
            {
                map[51 + 2 * (i / 50)][2 * (i % 50)] = '.';
            }

            Console.WriteLine("100 100");
            Array.ForEach(map, c =>
            {
                Array.ForEach(c, c1 => { Console.Write(c1); });
                Console.WriteLine();
            });
        }
    }
}