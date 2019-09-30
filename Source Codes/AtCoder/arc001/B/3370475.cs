using System;
using System.Linq;
//using System.Collections.Generic;
class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var s = Console.ReadLine();

        var correct = new int[4];
        var count = 0;
        for (var i = 0; i < 4; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (int.Parse(s[j].ToString()) == i+1) count++;
            }
            correct[i] = count;
            count = 0;
        }
        Console.WriteLine("{0} {1}", correct.Max(), correct.Min());
    }
}