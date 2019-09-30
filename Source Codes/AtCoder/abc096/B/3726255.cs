using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var data = Console.ReadLine().Split();
        var a = int.Parse(data[0]);
        var b = int.Parse(data[1]);
        var c = int.Parse(data[2]);

        var k = int.Parse(Console.ReadLine());

        var list = new List<int>();
        list.Add(a);
        list.Add(b);
        list.Add(c);

        var ary = list.OrderByDescending(x => x).ToArray();
        Console.WriteLine((ary[0] * Math.Pow(2, k)) + ary[1] + ary[2]);
    }
}