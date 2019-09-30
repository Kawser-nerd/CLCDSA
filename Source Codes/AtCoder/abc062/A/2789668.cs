using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

public class Program
{
    public static void Main()
    {
        var grA = new List<int> { 1, 3, 5, 7, 8, 10, 12 };
        var grB = new List<int> { 4, 6, 9, 11 };
        var line = ReadLine();
        var data = line.Split();
        var x = int.Parse(data[0]);
        var y = int.Parse(data[1]);

        if (x == 2 || y == 2)
        {
            WriteLine("No");
            return;
        }
        
        if ((grA.Contains(x) && grA.Contains(y)) ||
            (grB.Contains(x) && grB.Contains(y)))
        {
            WriteLine("Yes");
        }
        else
        {
            WriteLine("No");
        }
    }
}