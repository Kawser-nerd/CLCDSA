using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N;
    private int[] a;
    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }

    public void Solve()
    {
        Scan();
        int min = a.Min();
        int max = a.Max();
        if (max - min > 1)
        {
            Console.WriteLine("No");
            return;
        }
        if (max - min == 0)
        {
            if (a[0] == N - 1 || a[0] * 2 <= N)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
            return;
        }
        else if (max - min == 1)
        {
            int x = a.Count(i => i == min);
            int y = N - x;
            if (x < max && 2 * (max - x) <= y)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
            return;
        }
    }
}