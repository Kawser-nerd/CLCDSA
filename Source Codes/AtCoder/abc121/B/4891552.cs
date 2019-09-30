using System;

class ABC121_B
{
    static void Main(string[] args)
    {

        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);
        int C = int.Parse(input[2]);

        input = Console.ReadLine().Split(' ');
        int[] B = new int[M];
        for (int i = 0; i < M; i++)
        {
            B[i] = int.Parse(input[i]);
        }

        int[][] A = new int[N][];
        for (int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split(' ');
            A[i] = new int[M];
            for (int j = 0; j < M; j++)
            {
                A[i][j] = int.Parse(input[j]);
            }
        }

        int count = 0;

        for (int i = 0; i < N; i++)
        {
            int sum = C;
            for (int j = 0; j < M; j++)
            {
                sum += A[i][j] * B[j];
            }

            if (sum>0)
            {
                count++;
            }
        }

        Console.WriteLine(count);
    }
}