using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = line[0].ToUpper();
        var b = line[1].ToUpper();
        Console.WriteLine(a == b ? "Yes" : "No");
    }
}