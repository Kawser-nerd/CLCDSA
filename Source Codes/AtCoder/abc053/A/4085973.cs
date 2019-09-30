using System;
using System.Collections.Generic;
using System.Linq;
 
namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            var x = int.Parse(Console.ReadLine());
            if(x<1200) Console.WriteLine("ABC");
            else Console.WriteLine("ARC");
        }    
    }
}