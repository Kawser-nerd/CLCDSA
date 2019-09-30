using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        char c = Console.ReadLine()[0];
        
        Console.WriteLine(string.Join("", Console.ReadLine().Where(x => x != c)));
    }
}