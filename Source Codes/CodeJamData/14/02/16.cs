using System;
using System.Collections.Generic;
using System.Linq;

class B
{
    double Solve(double C, double F, double X)
    {
        double current = 0;
        var time = new double[]{0}.Union(Enumerable.Range(0, 200000).Select(i => current += C / (2 + F * i))).ToArray();
        return Enumerable.Range(0, time.Length).Min(i => time[i] + X / (2 + F * i));
    }

    static IEnumerable<string> Output()
    {
        var line = Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
        yield return new B().Solve(line[0],line[1],line[2]).ToString();
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}