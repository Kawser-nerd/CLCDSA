using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input1 = Console.ReadLine().Split(' ');
        int N = int.Parse(input1[0]);
        int M = int.Parse(input1[1]);
        int C = int.Parse(input1[2]);

        string[] input2 = Console.ReadLine().Split(' ');
        int[] B = new int[M];
        for(int i = 0; i < B.Length; i++)
        {
            B[i] = int.Parse(input2[i]);
        }
        int[,] A = new int[N, M];
        for (int i = 0; i < N; i++)
        {
            input2 = Console.ReadLine().Split(' ');
            for (int j = 0; j < M; j++)
            {
                A[i, j] = int.Parse(input2[j]);
            }
        }
        int c = 0;
        for(int i = 0; i < N; i++)
        {
            int sum = 0;
            for(int j = 0; j < M; j++)
            {
                sum += A[i, j] * B[j];
            }
            if (sum + C > 0)
                c++;
        }
        Console.WriteLine(c);
    }
}