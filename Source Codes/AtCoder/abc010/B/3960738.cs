using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    static int RemoveCount(int n )
    {
        foreach(int i in Enumerable.Range(0, n + 1))
        {
            int num = n - i;
            if((num & 1) == 1 &&
                num % 3 != 2)
                return i;
        }
        return n;
    }
    public Program()
    {
        int n = int.Parse(Console.ReadLine());
        int[] flowers = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int result =
            flowers.Select(RemoveCount)
            .Sum();
        Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}