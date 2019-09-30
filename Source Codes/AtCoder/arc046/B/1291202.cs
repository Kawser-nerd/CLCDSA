using System;
using System.Collections.Generic;
using System.Linq;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N, A, B;

    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        var l = Console.ReadLine().Split(' ');
        A = int.Parse(l[0]);
        B = int.Parse(l[1]);
    }



    public void Solve()
    {
        Scan();
        if (N <= A)
        {
            Console.WriteLine("Takahashi");
            return;
        }
        if (A == B)
        {
            if (N % (A + 1) == 0)
            {
                Console.WriteLine("Aoki");
            }
            else
            {
                Console.WriteLine("Takahashi");
            }
            return;
        }
        if (A > B)
        {
            Console.WriteLine("Takahashi");
            return;
        }
        else if (A < B)
        {
            Console.WriteLine("Aoki");
            return;
        }
    }
}