using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var L = int.Parse(line[0]);
        var x = int.Parse(line[1]);
        var y = int.Parse(line[2]);
        var s = int.Parse(line[3]);
        var d = int.Parse(line[4]);
        int ds;
        if (d > s) ds = d - s;
        else ds = d - s + L;
        if (y > x)
        {
            var t1 = (double)ds/ (double)(x + y);
            var t2 = (double)(L -ds) / (double)(y - x);
            Console.WriteLine(Math.Min(t1, t2));
        }
        else
        {
            var t1 = (double)ds / (double)(x + y);
            Console.WriteLine(t1);
        }
    }
}