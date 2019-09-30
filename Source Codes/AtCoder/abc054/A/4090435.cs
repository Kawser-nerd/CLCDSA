using System;
using System.Collections.Generic;
using System.Linq;
 
namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split(' ');
            var a = int.Parse(str[0]);
            var b = int.Parse(str[1]);

            if(a==b)
            {
                Console.WriteLine("Draw");
                return;
            }
            if(a==1) 
            {
                Console.WriteLine("Alice");
                return;
            }
            if(b==1) 
            {
                Console.WriteLine("Bob");
                return;
            }
            
            if(a<b) Console.WriteLine("Bob");
            if(a>b) Console.WriteLine("Alice");
        }    
    }
}