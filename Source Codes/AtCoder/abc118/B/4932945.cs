using System;
using System.Collections;
class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);
        BitArray flag = new BitArray(M, true);
        for(int i = 0; i < N; i++)
        {
            string[] input1 = Console.ReadLine().Split(' ');
            int K = int.Parse(input1[0]);
            BitArray f = new BitArray(M, false);
            for (int j = 1; j <= K; j++)
            {
                f.Set(int.Parse(input1[j]) - 1, true);
            }
            flag.And(f);
        }
        int n = 0;
        for(int i = 0; i < M; i++)
        {
            if (flag.Get(i) == true)
                n++;
        }
        Console.WriteLine(n);
    }
}