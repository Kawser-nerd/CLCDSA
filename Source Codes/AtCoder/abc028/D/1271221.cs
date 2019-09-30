using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}



public class Magatro
{
    private long N, K;

    private void Scan()
    {
        string[] line = Console.ReadLine().Split(' ');
        N = long.Parse(line[0]);
        K = long.Parse(line[1]);
    }

    public void Solve()
    {
        Scan();
        long bunbo = N * N * N;
        long bunsi = 0;
        bunsi += (K - 1) * (N - K) * 6;
        bunsi += (N - K) * 3;
        bunsi += (K - 1) * 3;
        bunsi++;
        Console.WriteLine((double)bunsi / (double)bunbo);
    }
}