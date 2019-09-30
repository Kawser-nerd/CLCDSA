using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int S = int.Parse(input[1]);
            int T = int.Parse(input[2]);
            int answer = 0;

            int[] Weight = new int[N];

            for (int i = 0; i < N; i++)
            {
                if (i==0)
                {
                    Weight[i] = int.Parse(Console.ReadLine());
                }
                else
                {
                    Weight[i] = Weight[i - 1] + int.Parse(Console.ReadLine());
                }
                if (Weight[i]>=S&&Weight[i]<=T)
                {
                    answer = answer + 1;
                }
            }
            Console.WriteLine(answer);
        }
    }
}