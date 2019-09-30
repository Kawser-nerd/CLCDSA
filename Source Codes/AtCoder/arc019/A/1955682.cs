using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.WriteLine(Console.ReadLine().Replace('O','0').Replace('D', '0').Replace('I', '1').Replace('Z', '2').Replace('S', '5').Replace('B', '8'));
    }
}