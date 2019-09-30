using System;
using System.Linq;

class Program
{
    static void Main()
    {
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int L = input[0];
        int H = input[1];
        int N = int.Parse(Console.ReadLine());
        for (int i = 0; i < N; i++)
        {
            int A = int.Parse(Console.ReadLine());
            if (A > H)
            {
                Console.WriteLine(-1);
            }
            else if (A < L)
            {
                Console.WriteLine(L - A);
            }
            else
            {
                Console.WriteLine(0);
            }
        }
    }
}