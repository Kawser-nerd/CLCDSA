using System;
using System.Linq;
using System.Collections.Generic;

namespace _0030
{
    
    class Program
    {

        
        static void Main(string[] args)
        {

            int n = int.Parse(Console.ReadLine());

            for(int y = 0; ; y++)
            {
                if(n - 7 * y < 0)
                {
                    Console.WriteLine("No");
                    break;
                }
                if((n - 7 * y) % 4 == 0)
                {
                    Console.WriteLine("Yes");
                    break;
                }
            }
       
        }
    }
}