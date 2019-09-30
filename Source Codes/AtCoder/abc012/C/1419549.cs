using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine();
        int N = int.Parse(input);

        var stream = Enumerable.Range(1, 9).SelectMany(i => Enumerable.Range(1, 9).Select(j => new {i, j})); 
        var total = stream.Sum(i => i.i * i.j);
        var diff = total - N;

        var strs = stream.Where(i => (i.i * i.j) == diff).Select(i => string.Format("{0} x {1}", i.i, i.j)).ToList();
        strs.ForEach(s => Console.WriteLine(s));
    }
}