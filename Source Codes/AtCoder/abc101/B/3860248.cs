using System;
using System.Linq;
using System.Collections.Generic;

namespace _0030
{
    
    class Program
    {

        
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int n = int.Parse(str);

            int sum = 0;

            for(int i = 0; i < str.Length; i++)
            {
                sum += int.Parse(str[i].ToString());
            }

            if(n % sum == 0)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }


        }
    }
}