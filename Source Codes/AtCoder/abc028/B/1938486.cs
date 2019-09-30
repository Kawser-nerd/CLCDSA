using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        Console.WriteLine($"{s.Count(x => x == 'A')} {s.Count(x => x == 'B')} {s.Count(x => x == 'C')} {s.Count(x => x == 'D')} {s.Count(x => x == 'E')} {s.Count(x => x == 'F')}");
    }
}