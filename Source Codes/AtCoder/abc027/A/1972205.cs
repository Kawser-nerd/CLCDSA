using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        Array.Sort(a);
        Console.WriteLine(a[0] == a[1] ? a[2] : a[0]);
    }
}