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
            var ab = int.Parse(str[0])*int.Parse(str[1]);

            for (int i = 1; i <= 3; i++)
            {
                if((ab*i)%2 == 1)
                {
                    Console.WriteLine("Yes");
                    return;
                }
            }
            Console.WriteLine("No");
        }
    }
}