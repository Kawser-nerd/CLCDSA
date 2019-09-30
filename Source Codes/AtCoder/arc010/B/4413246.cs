using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using System.Collections;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;


class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] holyday = new int[366];
        for (int i = 0; i < 366; i++)
        {
            var dayOfWeek = new DateTime(2012, 1, 1).AddDays(i).DayOfWeek;
            if (dayOfWeek == DayOfWeek.Saturday || dayOfWeek == DayOfWeek.Sunday) holyday[i]++;
        }
        for (int i = 0; i < n; i++)
        {
            int elapsedDate = DateTime.Parse("2012/" + Console.ReadLine()).DayOfYear - 1;
            holyday[elapsedDate]++;
        }

        int transfer = 0;
        int maxStreak = 0;
        int currentStreak = 0;
        for (int i = 0; i < 366; i++)
        {
            if (transfer != 0 && holyday[i] == 0)
            {
                transfer--;
                holyday[i]++;
            }
            if (holyday[i] > 0)
            {
                if (holyday[i] > 1)
                {
                    transfer++;
                    holyday[i]--;
                }
                currentStreak++;
            }
            else
            {
                maxStreak = Max(maxStreak, currentStreak);
                currentStreak = 0;
            }
        }
        maxStreak = Max(maxStreak, currentStreak);
        Console.WriteLine(maxStreak);
    }
}