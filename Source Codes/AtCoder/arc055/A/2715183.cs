using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var ret = '1' + new string('0', n - 1) + '7';
        Console.WriteLine(ret);
    }
}