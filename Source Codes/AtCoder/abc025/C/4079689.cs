using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;


class Program
{ 
    static int MinMax(int[] field, int[] yPoint, int[] xPoint, bool first)
    {
        if(field.All(x => x != 0))
        {
            var ret =
                Enumerable.Range(0, 9)
                .Where((x, i) => i % 3 != 2)
                .Select((i, index) => field[i] == field[i + 1] ? xPoint[index] : 0)
                .Sum() +
                field.Take(6)
                .Select((x , i) => x == field[i + 3] ? yPoint[i] : 0)
                .Sum();
            //Console.WriteLine(string.Join(",",field));
            //Console.WriteLine(ret);
            return ret;
        }
        else if(first)
            return 
                Enumerable.Range(0, 9)
                .Where(x => field[x] == 0)
                .Max(x => MinMax(field.Select((y, i) => i == x ? 1 : y).ToArray()
                    , yPoint, xPoint, !first));
        else
            return 
                Enumerable.Range(0, 9)
                .Where(x => field[x] == 0)
                .Min(x => MinMax(field.Select((y, i) => i == x ? 2 : y).ToArray()
                    , yPoint, xPoint, !first));
    }
    public void Slove()
    {
        var yPoint =
            Enumerable.Range(0, 2)
            .SelectMany(x => Console.ReadLine().Split().Select(int.Parse).ToArray())
            .ToArray();
        var xPoint =
            Enumerable.Range(0, 3)
            .SelectMany(x => Console.ReadLine().Split().Select(int.Parse).ToArray())
            .ToArray();
        var first = MinMax(new int[9], yPoint, xPoint, true);
        var second = yPoint.Sum() + xPoint.Sum() - first;
        Console.WriteLine($"{first}\n{second}");
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}