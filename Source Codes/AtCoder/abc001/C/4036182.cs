using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();
        double deg = int.Parse(cin[0]) / 10.0;
        double dis = Math.Round(int.Parse(cin[1]) / 60.0, 1, MidpointRounding.AwayFromZero);

        if (dis <= 0.2) Console.Write("C");
        else if (11.25 <= deg && deg < 33.75) Console.Write("NNE");
        else if (33.75 <= deg && deg < 56.25) Console.Write("NE");
        else if (56.25 <= deg && deg < 78.75) Console.Write("ENE");
        else if (78.75 <= deg && deg < 101.25) Console.Write("E");
        else if (101.25 <= deg && deg < 123.75) Console.Write("ESE");
        else if (123.75 <= deg && deg < 146.25) Console.Write("SE");
        else if (146.25 <= deg && deg < 168.75) Console.Write("SSE");
        else if (168.75 <= deg && deg < 191.25) Console.Write("S");
        else if (191.25 <= deg && deg < 213.75) Console.Write("SSW");
        else if (213.75 <= deg && deg < 236.25) Console.Write("SW");
        else if (236.25 <= deg && deg < 258.75) Console.Write("WSW");
        else if (258.75 <= deg && deg < 281.25) Console.Write("W");
        else if (281.25 <= deg && deg < 303.75) Console.Write("WNW");
        else if (303.75 <= deg && deg < 326.25) Console.Write("NW");
        else if (326.25 <= deg && deg < 348.75) Console.Write("NNW");
        else Console.Write("N");

        Console.Write(" ");

        if (dis <= 0.2) Console.WriteLine("0");
        else if (dis <= 1.5) Console.WriteLine("1");
        else if (dis <= 3.3) Console.WriteLine("2");
        else if (dis <= 5.4) Console.WriteLine("3");
        else if (dis <= 7.9) Console.WriteLine("4");
        else if (dis <= 10.7) Console.WriteLine("5");
        else if (dis <= 13.8) Console.WriteLine("6");
        else if (dis <= 17.1) Console.WriteLine("7");
        else if (dis <= 20.7) Console.WriteLine("8");
        else if (dis <= 24.4) Console.WriteLine("9");
        else if (dis <= 28.4) Console.WriteLine("10");
        else if (dis <= 32.6) Console.WriteLine("11");
        else Console.WriteLine("12");
    }
}