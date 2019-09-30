using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string[] s = Console.ReadLine().Split();
        string c = Console.ReadLine();
        string[] t = Console.ReadLine().Split();
        int o = 0;
        switch (t.Count(x => s.Contains(x)))
        {
            case 6:
            o = 1;
            break;
            case 5:
            if (t.Contains(c)) o = 2;
            else o = 3;
            break;
            case 4:
            o = 4;
            break;
            case 3:
            o = 5;
            break;
        }
        Console.WriteLine(o);
    }
}