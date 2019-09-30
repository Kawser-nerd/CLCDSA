using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        int firsthalf = -1;
        int nexthalf = -1;
        for (int i = 0; i < s.Length - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                if (firsthalf == -1)
                {
                    firsthalf = i;
                }
                else
                {
                    nexthalf = i;
                    break;
                }
            } 
        }
        int oto;
        if (nexthalf - firsthalf == 7)
        {
            oto = firsthalf + 8;
        }
        else
        {
            oto = nexthalf + 8;
        }
        oto %= 12;
        string res = "";
        switch (oto)
        {
            case 0:
            res = "Do";
            break;
            case 10:
            res = "Re";
            break;
            case 8:
            res = "Mi";
            break;
            case 7:
            res = "Fa";
            break;
            case 5:
            res = "So";
            break;
            case 3:
            res = "La";
            break;
            case 1:
            res = "Si";
            break;
        }
        Console.WriteLine(res);
    }
}