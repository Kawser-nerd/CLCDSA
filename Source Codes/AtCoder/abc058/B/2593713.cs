using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var o = Console.ReadLine();
        var e = Console.ReadLine();
        while(o.Any())
        {
            Console.Write(o.First());
            o = o.Substring(1);
            if (e.Any())
            {
                Console.Write(e.First());
                e = e.Substring(1);
            }
        }
        Console.WriteLine();
    }
}