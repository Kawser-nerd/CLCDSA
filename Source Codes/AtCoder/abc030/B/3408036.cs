using System;
using static System.Console;

class Program
{
    static void Main()
    {
        int n = NextInt();
        int m = NextInt();

        float deg = -1 * Math.Abs(HourToDegree(n, m) - MinuteToDegree(m));
        while (deg <= 0)
        {
            deg += 360;
        }
        WriteLine(Math.Min(deg, 360 - deg));
    }

    static float HourToDegree(int n, int m)
    {
        return (float)n / 12 * 360 + MinuteToDegree(m) / 12;
    }

    static float MinuteToDegree(int m)
    {
        return (float)m / 60 * 360;
    }

    static int NextInt()
    {
        return int.Parse(NextString());
    }

    static string NextString()
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