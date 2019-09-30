using System;
using System.Linq;

class Program
{
    public static void Main(string[] args)
    {
        int N = int.Parse(System.Console.ReadLine());

        int total = 0, oddMin = int.MaxValue;
        for (int i = 0; i < N; i++)
        {
            int score = int.Parse(System.Console.ReadLine());

            total += score;
            if (score<oddMin & score % 10 != 0)
            {
                oddMin = score;
            }
        }

        if (total % 10 == 0)
        {
            if (oddMin == int.MaxValue)
            {
                total = 0;
            }
            else
            {
                total -= oddMin;
            }
        }

        System.Console.WriteLine(total);
    }
}