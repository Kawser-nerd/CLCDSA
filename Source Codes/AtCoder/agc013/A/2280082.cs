using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var incdec = 0; var count = 0;
        var pre = a[0];
        for (int i = 1; i < n; i++)
        {
            if (incdec == 0 && pre < a[i]) incdec = 1;
            else if (incdec == 0 && pre > a[i]) incdec = -1;
            else if (incdec == 1 && pre > a[i]) { count++; incdec = 0; }
            else if (incdec == -1 && pre < a[i]) { count++; incdec = 0; }
            pre = a[i];
        }
        Console.WriteLine(count + 1);
    }
}