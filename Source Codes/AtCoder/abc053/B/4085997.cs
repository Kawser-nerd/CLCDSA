using System;
using System.Collections.Generic;
using System.Linq;
 
namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var i = 0;
            int a = 0;
            int b = 0;
            foreach (var item in s)
            {
                i++;
                if(item.ToString() == "A") if(a <= 0) a = i;
                if(item.ToString() == "Z") b = i;
            }
            Console.WriteLine(b-a+1);
        }    
    }
}