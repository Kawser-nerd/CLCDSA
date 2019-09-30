using System;
using System.Collections.Generic;
using System.Linq;
 
namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            int kotae = 0;

            var str = Console.ReadLine().Split(' ');
            int k = int.Parse(str[0]);
            int s = int.Parse(str[1]);

            for (int i = 0; i <= k; i++)
            {
                for (int o = 0; o <= k; o++)
                {
                    int z = s - i - o;
                    if(0<=z && z <= k) kotae++;                    
                }
            }
            Console.WriteLine(kotae);


            
        }        
    }
}