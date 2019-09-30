using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var p1 = 0; var p2 = 0; var p4 = 0;
        for (int i = 0; i < n; i++)
        {
            var w = int.Parse(line[i]);
            if (w % 4 == 0) p4++;
            else if (w % 2 == 0) p2++;
        }
        p1 = n - p4 - p2;
        Console.WriteLine(check(p1, p2, p4) ? "Yes" : "No");
    }
    public static bool check(int p1, int p2, int p4)
    {
        if (p1 == 0) return true;
        if (p4 == 0) return false;
        if (p2 == 0) return p1 - p4 <= 1;
        else return p1 <= p4;
    }
}