using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //int a = int.Parse(Console.ReadLine());
        //string s = Console.ReadLine();
        Console.WriteLine(string.Join(" ",Console.ReadLine().Split().Select(x => (x == "Left" ? "<" : (x == "Right" ? ">" : "A"))).ToArray()));
    }
}