using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = int.Parse(line[0]);
        var b = int.Parse(line[1]);
        string ret;
        if (a > 0) ret = "Positive";
        else if (a == 0 | b == 0 | (a < 0 && b > 0)) ret = "Zero";
        else if (a < 0 && b < 0 && (b - a + 1) % 2 == 0) ret = "Positive";
        else ret = "Negative";
        Console.WriteLine(ret);
    }
}