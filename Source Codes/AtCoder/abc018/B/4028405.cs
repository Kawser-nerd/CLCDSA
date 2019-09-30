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
        string input = Console.ReadLine();
        int[] change = Enumerable.Range(0, input.Length).ToArray();
        int n = int.Parse(Console.ReadLine());
        foreach(int i in Enumerable.Range(0, n))
        {
            string[] inputs = Console.ReadLine().Split();
            int start = int.Parse(inputs[0]) - 1;
            int end = int.Parse(inputs[1]);
            change.Take(end).Skip(start).Reverse().ToArray().CopyTo(change, start);
        }
        string result = string.Join("", change.Select(x => input[x]));
        Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}