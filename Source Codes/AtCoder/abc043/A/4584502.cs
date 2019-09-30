using System;
class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            int canNum = 0;

            for(int i = 0; i < N; i++)
            {
                canNum += (i + 1);
            }

            Console.WriteLine(canNum);
        }
    }