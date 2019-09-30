using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program
{
    static void Main()
    {
        string s = NextString();
        int t = NextInt();
        WriteLine(Calc(s)[t - 1]);
    }

    static int[] Calc(string S)
    {
        int x, y, t;
        x = y = t = 0;

        foreach (char v in S)
        {
            switch (v)
            {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                default:
                    t++;
                    break;
            }
        }
        int _base = Abs(x) + Abs(y);
        int maxResult = _base + t;
        int tmp = _base - t;
        int minResult;
        if (tmp >= 0)
            minResult = tmp;
        else
            minResult = Abs(tmp % 2);

        return new int[] { maxResult, minResult };
    }

    static string NextString()
    {
        var result = new List<char>();
        while (true)
        {
            int next = Read();
            if (next < 0)
                break;
            var nextChar = (char)next;
            if (!char.IsWhiteSpace(nextChar))
                result.Add(nextChar);
            else if (nextChar != '\r')
                break;
        }
        return string.Join("", result);
    }

    static int NextInt()
    {
        return int.Parse(NextString());
    }
}