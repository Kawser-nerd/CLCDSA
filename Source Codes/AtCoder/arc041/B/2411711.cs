using System;
using System.Linq;

namespace arc041_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[,] ban = new int[x[0], x[1]];
            for (int i = 0; i < x[0]; i++)
            {
                string s = Console.ReadLine();
                for (int j = 0; j < x[1]; j++)
                {
                    ban[i, j] = int.Parse(s[j].ToString());
                }
            }
            int[,] ret = new int[x[0], x[1]];
            int[,] move = new int[,]
            {
                { 1, 0 }, { -1, 0 },
                { 0, 1 }, { 0, -1 }
            };
            for (int i = 0; i < x[0] - 2; i++)
            {
                for (int j = 1; j < x[1] - 1; j++)
                {
                    ret[i + 1, j] = ban[i, j];
                    for (int k = 0; k < 4; k++)
                    {
                        ban[i + 1 + move[k, 0], j + move[k, 1]] -= ret[i + 1, j];
                    }
                }
            }
            for (int i = 0; i < x[0]; i++)
            {
                for (int j = 0; j < x[1]; j++)
                {
                    Console.Write(ret[i, j]);
                }
                Console.WriteLine();
            }
        }
    }
}