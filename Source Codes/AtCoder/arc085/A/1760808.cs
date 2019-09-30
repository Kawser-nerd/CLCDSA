using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split();
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);

        int power2 = 1;
        for (int i = 0; i < M; i++) power2 *= 2;

        Console.WriteLine(power2 * (1900 * M + (N - M) * 100));
        Console.ReadLine();
    }
}