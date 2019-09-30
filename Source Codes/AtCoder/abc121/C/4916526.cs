using System;
class Program
{
    static void Main(string[] args)
    {
        string[] input1 = Console.ReadLine().Split(' ');
        int N = int.Parse(input1[0]);
        int M = int.Parse(input1[1]);
        long[] A = new long[N];
        int[] B = new int[N];
        for(int i = 0; i < N; i++)
        {
            string[] input = Console.ReadLine().Split(' ');
            A[i] = long.Parse(input[0]);
            B[i] = int.Parse(input[1]);
        }
        Array.Sort(A, B);
        long c = 0;
        long sum = 0;
        for(int i = 0; i < N; i++)
        {
            if(c + B[i] >= M)
            {
                sum += (M - c) * A[i];
                break;
            }
            else
            {
                sum += A[i] * B[i];
                c += B[i];
            }
        }
        Console.WriteLine(sum);
    }
}