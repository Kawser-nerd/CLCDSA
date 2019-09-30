using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        var N = int.Parse(Console.ReadLine());
        var line = Console.ReadLine();
        var Ws = new int[N];
        var Es = new int[N];
        var leftW = new int[N];
        var rightE = new int[N];
        leftW[0] = 0;
        rightE[N-1] = 0;
        for (int i = 1; i < N; i++)
        {
            if (line[i-1] == 'W')
            {
                leftW[i] = leftW[i-1]+1;
            }
            else
            {
                leftW[i] = leftW[i - 1];
            }
        }
        for (int i = N-2; i >= 0; i--)
        {
            if (line[i+1] == 'W')
            {
                rightE[i] = rightE[i + 1];
            }
            else
            {
                rightE[i] = rightE[i + 1]+1;
            }
        }
        var min = int.MaxValue;
        for (int i = 0; i < N; i++)
        {
            var val = leftW[i] + rightE[i];
            if (val < min)
            {
                min = val;
            }
        }
        Console.WriteLine(min);
    }
}