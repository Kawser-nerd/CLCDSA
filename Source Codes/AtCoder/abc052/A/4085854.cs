using System;
using System.Collections.Generic;
using System.Linq;
 
namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            var hen = Console.ReadLine().Split(' ');
            var a = int.Parse(hen[0]) * int.Parse(hen[1]);
            var b = int.Parse(hen[2]) * int.Parse(hen[3]);
            if(a>b) Console.WriteLine(a);
            else Console.WriteLine(b);
        }        
    }
}