using System;
using System.Collections.Generic;
using System.Linq;
 
namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            var y = int.Parse(Console.ReadLine());
            if(DateTime.IsLeapYear(y)) Console.WriteLine("YES");
            else Console.WriteLine("NO");
            
        }
    }
}