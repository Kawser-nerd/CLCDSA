using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        int count = int.Parse(Console.ReadLine());
        var line = Console.ReadLine();
        int min = 0;
        for(int i = 1; i < count; ++i)
        {
            if (line[i] == 'E') ++min;
        }
        int now = min;
        for(int leader = 0; leader < count - 1; ++leader)
        {
            if (line[leader] == 'W') ++now;
            if (line[leader + 1] == 'E') --now;
            if (now < min) min = now;
        }
        Console.WriteLine(min);
    }
}