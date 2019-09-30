using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

public class Program
{
    public static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N, va, vb, L;

    private void Scan()
    {
        string[] line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        va= int.Parse(line[1]);
        vb = int.Parse(line[2]);
        L = int.Parse(line[3]);
    }

    public void Solve()
    {
        Scan();
        double dist = L;
        for(int i = 0; i < N; i++)
        {
            double time = dist / va;
            dist = time * vb;
        }
        Console.WriteLine("{0:f9}",dist);
    }
}