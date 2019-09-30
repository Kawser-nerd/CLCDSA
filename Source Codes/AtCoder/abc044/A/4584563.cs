using System;
class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int K = int.Parse(Console.ReadLine());
            int X = int.Parse(Console.ReadLine());
            int Y = int.Parse(Console.ReadLine());

            int fee = 0;

            for(int i = 1; i <= N; i++)
            {
                if(i <= K)
                {
                    fee += X;
                }
                else
                {
                    fee += Y;
                }
            }

            Console.WriteLine(fee);
        }
    }