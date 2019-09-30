using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private string A = Console.ReadLine();
    public void Solve()
    {
        long[]count = new long[256];
        foreach(char c in A)
        {
            count[c]++;
        }
        long length = A.Length;
        long anser = (length-1)*(length)/2+1;
        foreach(long i in count)
        {
            anser-=(i-1)*(i)/2;
        }
        Console.WriteLine(anser);
    }
}