using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public Program()
    {
        int n = int.Parse(Console.ReadLine());
        int[] hist = new int[1001];
        foreach(int i in Enumerable.Range(0, n))
            hist[int.Parse(Console.ReadLine())]++;
        foreach(int i in Enumerable.Range(0, 1001).Reverse())
            if(hist[i] != 0)
                foreach(int j in Enumerable.Range(0, i).Reverse())
                {
                    if(hist[j] != 0)
                    {
                        Console.WriteLine(j);
                        return;
                    }
                }
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}