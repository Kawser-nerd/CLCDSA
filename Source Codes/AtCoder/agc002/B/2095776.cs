using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var a = new int[n + 1];
        var p = new bool[n + 1];
        p[1] = true;
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var x = int.Parse(line[0]);
            var y = int.Parse(line[1]);
            a[x]--;
            a[y]++;
            if (p[x]) p[y] = true;
            if (a[x] == -1 && p[x]) p[x] = false;
        }
        var c = p.Where(x => x == true).Count();
        Console.WriteLine(c);
    }
}