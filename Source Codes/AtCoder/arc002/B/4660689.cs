using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static void Next(ref int Y,ref int M,ref int D)
    {
        if (M == 12 && D == 31)
        {
            Y++;
            M = 1;
            D = 1;
        }
        else if (
            (M == 1 && D == 31) ||
            (M == 3 && D == 31) ||
            (M == 4 && D == 30) ||
            (M == 5 && D == 31) ||
            (M == 6 && D == 30) ||
            (M == 7 && D == 31) ||
            (M == 8 && D == 31) ||
            (M == 9 && D == 30) ||
            (M == 10 && D == 31) ||
            (M == 11 && D == 30) ||
            (M == 2 && (((Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) && D == 29) || (!(Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) && D == 28))))
        {
            M++;
            D = 1;
        }
        else
            D++;
    }
    public static void Main()
    { 
        var s=Console.ReadLine().Split('/');
        int Y = int.Parse(s[0]);
        int M = int.Parse(s[1]);
        int D = int.Parse(s[2]);
        while (Y%(M*D)!=0)
            Next(ref Y,ref M,ref D);
        Console.WriteLine(Y + "/" + M.ToString().PadLeft(2, '0') + "/" + D.ToString().PadLeft(2, '0'));
    }
}