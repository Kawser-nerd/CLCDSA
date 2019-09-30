using System.Linq;
using System;

class Program
{
    static void Main()
    {
        B();
    }

    static void B()
    {
        var input = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        var N = input[0];
        var A = input[1];
        var B = input[2];
        var C = input[3];
        var D = input[4];
        
        for (int i = 0; i < N; i++)
        {
            if ((N - 1 - i) * C - i * D <= B - A && (N - 1 - i) * D - i * C >= B - A)
            {
                Console.WriteLine("YES");
                return;
            }
        }
        Console.WriteLine("NO");
    }
    
}