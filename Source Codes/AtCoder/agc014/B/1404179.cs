using System;

class program
{
    static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split();
        long N = long.Parse(inputs[0]);
        long M = long.Parse(inputs[1]);
        long[] count = new long[N];
        bool ans = true;

        for(long i = 0; i < M; i++)
        {
            inputs = Console.ReadLine().Split();
            long p = long.Parse(inputs[0]) - 1;
            long q = long.Parse(inputs[1]) - 1;
            count[p]++;
            count[q]++;
        }
        
        for(long i = 0; i < N; i++)
        {
            if (count[i] % 2 != 0)
            {
                ans = false;
                break;
            }
        }

        if (ans) Console.WriteLine("YES");
        else Console.WriteLine("NO");

    }
}