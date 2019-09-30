using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    static bool OccurBug(int[][] question, int level, int value)
    {
        if(level == question.Length)
            return value == 0;
        else
        {
            return question[level].Any(x => OccurBug(question, level + 1, value ^ x));
        }
    }
    public void Slove()
    {
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int k = int.Parse(inputs[1]);
        int[][] question =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine().Split()
                .Select(int.Parse).ToArray())
            .ToArray();
        bool existBug = OccurBug(question, 0, 0);
        Console.WriteLine(existBug ? "Found" : "Nothing");
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}