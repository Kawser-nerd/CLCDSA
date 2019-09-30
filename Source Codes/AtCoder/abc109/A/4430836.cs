using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] ab = Console.ReadLine().Split();
            int a = int.Parse(ab[0]);
            int b = int.Parse(ab[1]);

            if(a%2==0 || b%2==0)  
            {
                Console.WriteLine("No");
            }else{
                Console.WriteLine("Yes");
            }
        }
    }
}