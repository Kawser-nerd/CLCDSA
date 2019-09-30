using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var HW = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var hw = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

        Console.WriteLine((HW[0] - hw[0]) * (HW[1] - hw[1]));
    }
}