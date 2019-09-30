using System;
using System.Collections.Generic;
using System.Linq;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int NA, NB;
    private Dictionary<string, int> Map = new Dictionary<string, int>();

    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        NA = int.Parse(line[0]);
        NB = int.Parse(line[1]);
        line = Console.ReadLine().Split(' ');
        foreach (string s in line)
        {
            Map[s] = 1;
        }
        line = Console.ReadLine().Split(' ');
        foreach (string s in line)
        {
            int o;
            if (!Map.TryGetValue(s, out o))
            {
                Map[s] = 0;
            }
            Map[s]++;
        }
    }



    public void Solve()
    {
        Scan();
        int and = 0;
        int or = 0;
        foreach(var pair in Map)
        {
            if(pair.Value == 2)
            {
                and++;
            }
            if (pair.Value >= 1)
            {
                or++;
            }
        }
        Console.WriteLine((double)and / or);
    }
}