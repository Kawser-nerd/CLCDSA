using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var ans = new int[6];
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            var a = double.Parse(line[0]);
            var b = double.Parse(line[1]);
            getAns(ans, a, b);
        }
        Console.WriteLine(string.Join(" ",ans));
    }
    public static void getAns (int[] ans, double a, double b)
    {
        if (a >= 35) ans[0]++;
        else if (a >= 30) ans[1]++;
        else if (a >= 25) ans[2]++;
        if (b >= 25) ans[3]++;
        if (a >= 0 && b < 0) ans[4]++;
        if (a < 0) ans[5]++;
    }
}