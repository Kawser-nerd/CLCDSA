using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var res = 0;
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            var a = int.Parse(line[0]);
            var b = int.Parse(line[1]);
            res += a * b;
        }
        Console.WriteLine((int)(res * 1.05));
    }
}