using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        Console.ReadLine();
        string name = Console.ReadLine();
        string kit = Console.ReadLine();
        int[] Tname = new int[26];
        int[] Kname = new int[26];
        for (int i = 0; i < name.Length; i++)
            Tname[name[i] - 'A']++;
        for (int i = 0; i < kit.Length; i++)
            Kname[kit[i] - 'A']++;

        int min = 1;
        for(int i = 0; i < 26; i++)
        {
            if (Tname[i] == 0)
                continue;
            if (Kname[i] == 0)
            {
                min = -1;
                break;
            }
            while (Kname[i] * min < Tname[i])
                min++;
        }
        Console.WriteLine(min);
    }
}