using System;
using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var num = ToInt32(ReadLine());
        var x = 0;
        var y = 0;
        var qusCounter = 0;
        for (var i = 0; i < str.Length; i++)
        {
            switch (str.Substring(i, 1))
            {
                case "L":
                    x -= 1;
                    break;
                case "R":
                    x += 1;
                    break;
                case "U":
                    y += 1;
                    break;
                case "D":
                    y -= 1;
                    break;
                case "?":
                    qusCounter++;
                    break;
            }
        }

        for (var i = 0; i < qusCounter; i++)
        {
            if (num == 1)
            {
                if (Math.Abs(x) >= Math.Abs(y))
                {
                    x = x >= 0 ? ++x : --x;
                }
                else
                {
                    y = y >= 0 ? ++y : --y;
                }
            }
            else
            {
                if (Math.Abs(x) >= Math.Abs(y))
                {
                    x = x >= 0 ? --x : ++x;
                }
                else
                {
                    y = y >= 0 ? --y : ++y;
                }
            }
        }
        WriteLine(Math.Abs(x) + Math.Abs(y));
    }
}