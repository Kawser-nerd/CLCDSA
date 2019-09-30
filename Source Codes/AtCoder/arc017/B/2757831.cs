using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var k = int.Parse(line[1]);
        var pre = int.Parse(Console.ReadLine().Trim());
        var count = 0;
        var ctn = 1;
        for (int i = 1; i < n; i++)
        {
            var w = int.Parse(Console.ReadLine().Trim());
            if (w > pre) ctn++;
            else
            {
                count += Math.Max(0, ctn - k + 1);
                ctn = 1;
            }
            pre = w;
        }
        count += Math.Max(0, ctn - k + 1);
        Console.WriteLine(count);
    }
}