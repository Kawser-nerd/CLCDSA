using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int a = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        Console.WriteLine("".PadLeft((a - 1) / 9 + 1, ((a - 1) % 9 + 1).ToString()[0]));
    }
}