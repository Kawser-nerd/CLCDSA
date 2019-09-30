using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var x = int.Parse(line[0]);
        var y = int.Parse(line[1]);
        var k = int.Parse(Console.ReadLine().Trim());
        Console.WriteLine(y >= k ? x + k : 2 * y + x - k);
    }
}