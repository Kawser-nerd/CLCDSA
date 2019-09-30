using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var inputs = Console.ReadLine().Split(' ');
        int N = int.Parse(inputs[0]);
        int Q = int.Parse(inputs[1]);
        var S = Console.ReadLine();
        var t = new int[N + 1];

        // ?????0?i????????????
        t[0] = 0;
        for(int i = 1; i < N; i++)
        {
            int count = 0;
            if(i + 1 <= N &&
                S[i - 1] == 'A' &&
                S[i] == 'C')
            {
                count++;
            }
            
            t[i] = t[i-1] + count;
        }

        for (int i = 0; i < Q; i++)
        {
            inputs = Console.ReadLine().Split(' ');
            int l = int.Parse(inputs[0]);
            int r = int.Parse(inputs[1]);
            int count = t[r - 1] - t[l - 1];
            Console.WriteLine(count);
        }
    }
}