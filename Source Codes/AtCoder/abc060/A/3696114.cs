using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var data = Console.ReadLine().Split();
        var a = data[0];
        var b = data[1];
      	var c = data[2];
      
        if (a.Last() == b.First() && b.Last() == c.First())
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}