using System.Collections.Generic;
using System.Linq;
using System;

class Program
{
    static int N;
    static List<int>[] E;

    static void Main()
    {
        D();
    }

    static void D()
    {
        N = int.Parse(Console.ReadLine());
        
        E = new List<int>[N];
        for (int i = 0; i < N; i++) E[i] = new List<int>();
        for (long i = 0; i < N - 1; i++)
        {
            var XY = Console.ReadLine().Split(' ').Select(x => int.Parse(x) - 1);
            E[XY.ElementAt(0)].Add(XY.ElementAt(1));
            E[XY.ElementAt(1)].Add(XY.ElementAt(0));
        }

        Console.WriteLine(Grundy(0, 0) == 0 ? "Bob" : "Alice");
    }

    static int Grundy(int root, int prev)
    {
        int ans = 0;
        
        foreach (var n in E[root])
        {
            if (n != prev) ans ^= Grundy(n, root) + 1;
        }

        return ans;
    }
}