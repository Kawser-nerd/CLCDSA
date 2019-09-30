using System;
using System.Linq;
using System.Collections.Generic;

namespace _0030
{
    
    class Program
    {

        
        static void Main(string[] args)
        {
            string a = Console.ReadLine();
            string b = Console.ReadLine();
            

            //??????????????Yes
            if(a == b)
            {
                Console.WriteLine("Yes");
                return;
            }

            //???????????????????
            if(a.Length != b.Length)
            {
                Console.WriteLine("No");
                return;
            }

            string substr;
            string sn;
            string strnow = a;
           
            int n = a.Length;
            
            //a????????
            for (int i = 0; i < n; i++)
            {
                substr = strnow.Substring(0, n - 1);
                sn = strnow[n - 1].ToString();
                strnow = sn + substr;

                if(strnow == b)
                {
                    Console.WriteLine("Yes");
                    return;
                }
            }

            Console.WriteLine("No");
 
       
        }
    }
}