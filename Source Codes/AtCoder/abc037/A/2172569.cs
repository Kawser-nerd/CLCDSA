using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = int.Parse(line[0]);
        var b = int.Parse(line[1]);
        var c = int.Parse(line[2]);
        Console.WriteLine(a > b ? c / b : c / a);
    }
}