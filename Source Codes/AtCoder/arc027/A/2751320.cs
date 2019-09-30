using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var ans = new DateTime(2000,1,1,18, 0, 0) - new DateTime(2000,1,1,h, m, 0);
        Console.WriteLine(ans.Hours * 60 + ans.Minutes);
    }
}