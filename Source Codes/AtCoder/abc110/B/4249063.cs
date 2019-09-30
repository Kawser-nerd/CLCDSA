using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int M = int.Parse(input[1]);
            int X = int.Parse(input[2]);
            int Y = int.Parse(input[3]);

            string[] StrX = Console.ReadLine().Split(' ');
            string[] StrY = Console.ReadLine().Split(' ');

            List<int> ListX = new List<int>();
            List<int> ListY = new List<int>();

            for (int i = 0; i < N; i++)
            {
                ListX.Add(int.Parse(StrX[i]));
            }
            ListX.Add(X);

            for (int j = 0; j < M; j++)
            {
                ListY.Add(int.Parse(StrY[j]));
            }
            ListY.Add(Y);

            if (ListX.Max()<ListY.Min())
            {
                Console.WriteLine("No War");
            }
            else
            {
                Console.WriteLine("War");
            }
        }
    }
}