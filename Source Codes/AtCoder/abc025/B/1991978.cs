using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var a = int.Parse(line[1]);
        var b = int.Parse(line[2]);
        var pos = 0;
        for (int i = 0; i < n; i++)
        {
            string[] line2 = Console.ReadLine().Trim().Split(' ');
            var s = line2[0];
            var d = int.Parse(line2[1]);
            pos += getCommand(a, b, s, d);
        }
        if (pos > 0) Console.WriteLine("East {0}", pos);
        else if (pos < 0) Console.WriteLine("West {0}", -pos);
        else Console.WriteLine(0);
    }
    public static int getCommand(int a, int b, string s, int d)
    {
        int sign;
        if (s == "East") sign = 1;
        else sign = -1;
        if (d > b) d = b;
        else if (d < a) d = a;
        return d * sign;
    }
}