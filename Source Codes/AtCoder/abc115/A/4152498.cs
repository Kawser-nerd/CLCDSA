using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        var day = int.Parse(Console.ReadLine());
        if(day == 25)
        {
            Console.WriteLine("Christmas");
        }
        else if(day == 24)
        {
            Console.WriteLine("Christmas Eve");
        }
        else if(day == 23)
        {
            Console.WriteLine("Christmas Eve Eve");
        }
        else if(day == 22)
        {
            Console.WriteLine("Christmas Eve Eve Eve");
        }
    }
}