using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var a = int.Parse(line[1]);
        var b = int.Parse(line[2]);
        var res = 0;
        if (n > 5) res = (n - 5) * a + 5 * b;
        else res = n * b;
        Console.WriteLine(res);
    }
}