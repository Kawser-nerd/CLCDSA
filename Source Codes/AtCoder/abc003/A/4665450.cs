using System;

namespace BeginnerContest_003_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine());

            double yen = 10000;
            double div = 1.0 / x;
            double avg = 0;
            for (int i=0; i<x; i++)
            {
                avg += yen * div;
                yen += 10000;
            }
            Console.WriteLine(avg);
        }
    }
}