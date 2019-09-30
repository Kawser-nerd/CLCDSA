using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

class Magatro
{

    private int C;
    private int Nmax, Mmax, Lmax;
    public void Solve()
    {
        C = int.Parse(Console.ReadLine());
        for(int i = 0; i < C; i++)
        {
            var line = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            Array.Sort(line);
            Nmax = Math.Max(Nmax, line[0]);
            Mmax = Math.Max(Mmax, line[1]);
            Lmax = Math.Max(Lmax, line[2]);
        }

        Console.WriteLine(Nmax * Mmax * Lmax);
    }
}