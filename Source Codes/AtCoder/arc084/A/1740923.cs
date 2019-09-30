using System;
using System.Numerics;

class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());

        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N];

        string[] lineA = Console.ReadLine().Split();
        string[] lineB = Console.ReadLine().Split();
        string[] lineC = Console.ReadLine().Split();

        for (int i = 0; i < N; i++)
        {
            A[i] = int.Parse(lineA[i]);
            B[i] = int.Parse(lineB[i]);
            C[i] = int.Parse(lineC[i]);
        }

        // First, sort them all
        Array.Sort(A);
        Array.Sort(B);
        Array.Sort(C);

        BigInteger answer = 0;

        // Now we'll loop over the ones in B
        for (int i = 0; i < N; i++)
        {
            // We need the number of As _less_ than B[i] then the number of Cs _greater_ than B[i]
            int high = N - 1;
            int low = -1;
            while (high > low)
            {
                int mid = (low + high + 1) / 2;
                if (A[mid] < B[i]) low = mid;
                else high = mid - 1;
            }
            int Acount = low + 1;
            //Console.Error.WriteLine("Number of A less than {0}: {1}", B[i], Acount);

            high = N;
            low = 0;
            while (high > low)
            {
                int mid = (low + high) / 2;
                if (C[mid] > B[i]) high = mid;
                else low = mid + 1;
            }
            int Ccount = N - high;
            //Console.Error.WriteLine("Number of Cs greater than {0}: {1}", B[i], Ccount);

            answer += (BigInteger)Acount * (BigInteger)Ccount;
        }

        Console.WriteLine(answer);
        Console.ReadLine();
    }
}