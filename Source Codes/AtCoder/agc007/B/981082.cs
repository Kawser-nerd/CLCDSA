using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Magatro
{
    static int N = int.Parse(Console.ReadLine());
    static int[] P = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
    static void Main()
    {
        long[] A = new long[N];
        long[] B = new long[N];
        int[] R = new int[N]; 
        for(int i = 0; i < N; i++)
        {
            R[P[i] - 1] = i + 1;
        }
for(int i = 0; i < N; i++)
        {
            A[i] = 30000 * (i + 1);
            B[i] = 30000*(N - i + 1) + R[i];
        }
        Write(A, B);
    }
    static void Write(long[] A, long[] B)
    {
        long min = A.Min();
        for(int i = 0; i < N-1; i++)
        {
            Console.Write(A[i]-min+1);
            Console.Write(" ");
        }
        Console.Write(A[N - 1]-min+1);
        Console.WriteLine();
        min = B.Min();
        for (int i = 0; i < N - 1; i++)
        {
            Console.Write(B[i]-min+1);
            Console.Write(" ");
        }
        Console.Write(B[N - 1]-min+1);
        Console.WriteLine();
    }
}