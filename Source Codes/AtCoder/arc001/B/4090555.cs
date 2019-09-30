using System;
using System.Collections.Generic;
using System.Linq;
 
namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            var a = 0;
            var b = 0;
            var c = 0;
            var d = 0;

            
            
            var n = int.Parse(Console.ReadLine());
            var ca = Console.ReadLine();
            
            for (int i = 0; i < ca.Length; i++)
            {
                if(ca[i].ToString()=="1") a++;
                else if(ca[i].ToString()=="2") b++;
                else if(ca[i].ToString()=="3") c++;
                else if(ca[i].ToString()=="4") d++;
            }

            var list = new List<int>()
            {
                a,b,c,d
            };

            Console.WriteLine(list.Max()+" "+list.Min());

        }    
    }
}