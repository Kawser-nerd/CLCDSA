using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());
        var input = Console.ReadLine().Split(' ');
        var start = Convert.ToInt32(input[0]);
        var end = Convert.ToInt32(input[1]);
        var passFig = Convert.ToInt32(Console.ReadLine());
        var input2 = Console.ReadLine().Split(' ');
        var passNumbers = new HashSet<int> { start, end };

        var result = "YES";

        for (var i = 0; i < passFig; i++)
        {
            var fig = Convert.ToInt32(input2[i]);
            if (passNumbers.Contains(fig)) { result = "NO";break; }
            passNumbers.Add(fig);
        }
        Console.WriteLine(result);
    }
}