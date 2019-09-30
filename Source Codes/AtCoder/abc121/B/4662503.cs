using System;
using System.Linq;
class Problem
{
    static void Main(string[] args)
    {
        
        string[] num = Console.ReadLine().Split(' ');
        int N = int.Parse(num[0]);
        int M = int.Parse(num[1]);
        int C = int.Parse(num[2]);

        int[] b = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[,] a = new int[N, M];
        int[] preA = new int[M];
      ?int i, j;

        for(i=0; i<N; i++)
        {
            preA = Console.ReadLine().Split().Select(int.Parse).ToArray();
            for(j=0; j<M; j++)
            {
                a[i, j] = preA[j];
            }
            
        }

        int ans = 0;
        int x = C;

        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                x += a[i, j] * b[j];
            }
            if (x > 0){
                ans += 1;
            }
            x = C;
        }
        Console.WriteLine(ans);
    }
}