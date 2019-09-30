using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input1 = Console.ReadLine().Split();
            string[] input2 = Console.ReadLine().Split();

            int A, B, C, K, S, T;
            A = int.Parse(input1[0]);
            B = int.Parse(input1[1]);
            C = int.Parse(input1[2]);
            K = int.Parse(input1[3]);

            S = int.Parse(input2[0]);
            T = int.Parse(input2[1]);
            int answer = 0;
            if (S+T>=K)
            {
                answer = A * S + B * T - (S + T) * C;
                Console.WriteLine(answer);
            }
            else
            {
                answer = A * S + B * T;
                Console.WriteLine(answer);
            }
        }
    }
}