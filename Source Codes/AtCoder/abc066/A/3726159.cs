using System;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var data = Console.ReadLine().Split();
        var abc = data.Select(x => int.Parse(x)).OrderBy(x => x).ToArray();

        Console.WriteLine(abc[0] + abc[1]);
    }
}