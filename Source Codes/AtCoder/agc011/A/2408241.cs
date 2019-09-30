using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = long.Parse(line[0]);
        var c = long.Parse(line[1]);
        var k = long.Parse(line[2]);
        var a = new int[n];
        for (int i = 0; i < n; i++) a[i] = int.Parse(Console.ReadLine().Trim());
        Array.Sort(a);
        var tcount = 0;
        var bcount = 1;
        var startmax = a[0] + k;
        for (int i = 1; i < n; i++)
        {
            if (bcount == 0) { bcount++; startmax = a[i] + k; }
            else
            {
                if (a[i] <= startmax && bcount + 1 == c) { tcount++; bcount = 0; }
                else if (a[i] <= startmax && bcount + 1 < c) bcount++;
                else { tcount++; bcount = 1; startmax = a[i] + k; }
            }
        }
        if (bcount > 0) tcount++;
        Console.WriteLine(tcount);
    }
}