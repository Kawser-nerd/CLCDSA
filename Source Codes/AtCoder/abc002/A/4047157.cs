using System;
using System.Collections.Generic;
using System.Linq;

namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');   
            int a = int.Parse(str[0]);
            int b = int.Parse(str[1]);
            if(a>b)
            {
                Console.WriteLine(a);
            }    
            else
            {
                Console.WriteLine(b);
            }
        }
    }
}