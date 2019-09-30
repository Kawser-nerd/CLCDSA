using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] day = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int[] ymd = Console.ReadLine().Split('/').Select(int.Parse).ToArray();
        for (int i = ymd[2]; i <= day[ymd[1] - 1] + (ymd[1] == 2 && isUruu(ymd[0]) ? 1 : 0); i++)
        { 
            if (ymd[0] % (ymd[1] * i) == 0)
            {
                ymd[2] = i;
                goto end;
            }
        }
        for (int i = ymd[1] + 1; i <= 12; i++)
        {
            if(ymd[0] % i == 0)
            {
                ymd[1] = i;
                ymd[2] = 1;
                goto end;
            }
        }
        ymd[0]++;
        ymd[1] = 1;
        ymd[2] = 1;
        end: Console.WriteLine($"{ymd[0]}/{ymd[1]:00}/{ymd[2]:00}");
    }
    static bool isUruu(int y) => (y % 4) == 0 && ((y % 100) != 0 || (y % 400) == 0);
}