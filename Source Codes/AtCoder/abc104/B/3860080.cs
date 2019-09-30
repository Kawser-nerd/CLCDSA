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

            //4???????
            if(str.Length < 4)
            {
                Console.WriteLine("WA");
                return;
            }

            //1????A
            if(str[0] != 'A')
            {
                Console.WriteLine("WA");
                return;
            }

            //2???????
            if (char.IsUpper(str[1]))
            {
                Console.WriteLine("WA");
                return;
            }
           
            int ccnt = 0;  //C????????????

            //C????????
            for(int i = 2; i < str.Length - 1; i++)
            {
                if(str[i] == 'C')
                {                    
                    ccnt++;
                }
                else
                {
                    //C??????????WA
                    if (char.IsUpper(str[i]))
                    {
                        Console.WriteLine("WA");
                        return;
                    }
                }               
                
            }

            //C?2???????WA
            if (ccnt != 1)
            {
                Console.WriteLine("WA");
                return;
            }

            //???1??????
            if (char.IsUpper(str[str.Length - 1]))
            {
                Console.WriteLine("WA");
                return;
            }
            else
            {
                Console.WriteLine("AC");
            }        
       
        }
    }
}