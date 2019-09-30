using System;
using static System.Console;

class Program
{
    static void Main()
    {
        int[] circles = getCircles();
        double ans = GetArea(circles);

        WriteLine(ans.ToString("f6"));
    }

    static int[] getCircles()
    {
        var n = NextInt();
        var result = new int[n];

        for (var i = 0; i < result.Length; i++)
        {
            var r = NextInt();
            result[i] = r;
        }
        return result;
    }

    static double GetArea(int[] circles)
    {
        Array.Sort(circles);
        double result = 0;

        for (var i = 0; i < circles.Length; i++)
        {
            int j = circles.Length - 1 - i;
            double r = circles[j];
            double area = r * r * Math.PI;
            result += area * new int[] { 1, -1 }[i % 2];
        }
        return result;
    }

    static int NextInt()
    {
        return int.Parse(NextStr());
    }

    static string NextStr()
    {
        var result = "";
        while (true)
        {
            int tmp0 = Read();
            if (tmp0 < 0)
                break;
            var tmp = (char)tmp0;
            if (!string.IsNullOrWhiteSpace(tmp + ""))
                result += tmp;
            else if (tmp != '\r')
                break;
        }
        return result;
    }
}