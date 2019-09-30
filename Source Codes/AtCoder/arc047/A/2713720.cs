using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var L = int.Parse(line[1]);
        var s = Console.ReadLine().Trim();
        var count = 0;
        var open = 1;
        for (int i = 0; i < n; i++)
            if (s[i] == '+')
            {
                open++;
                if (open > L) { count++; open = 1; }
            }
            else open--;
        Console.WriteLine(count);
    }
}