using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public void Slove()
    {
        int[] data = new int[1000002];
        int n = int.Parse(Console.ReadLine());
        foreach(int i in Enumerable.Range(0, n))
        {
            int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
            data[inputs[0]]++;
            data[inputs[1] + 1]--;
        }
        int max = 0;
        int sum = 0;
        foreach(int value in data.Where(x => x != 0))
        {
            sum += value;
            max = Math.Max(max, sum);
        }
        Console.WriteLine(max);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}