using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Numerics;




namespace contest
{

    class contest
    {


        static void Main(string[] args)
        {


            //int n = int.Parse(Console.ReadLine());
            //var input = Console.ReadLine().Split().Select(int.Parse).ToArray();

            //var num = Console.ReadLine().Split().Select(int.Parse).ToArray();



            //int n = int.Parse(Console.ReadLine());


            //int n = int.Parse(Console.ReadLine());
            //var array = Console.ReadLine().Split().Select(int.Parse).ToArray();

            string s = Console.ReadLine();

            

            //bool check = true;
            string tmp = "";
            for(int i=s.Length-1; i>=0; i--)
            {
                tmp += s[i];

                if (tmp.Length == 5 && (tmp == "maerd" || tmp == "esare"))
                {
                    tmp = "";
                }
                else if (tmp.Length == 6 && tmp == "resare")
                {
                    tmp = "";
                }
                else if (tmp.Length == 7 && tmp == "remaerd")
                {
                    tmp = "";
                }
                else if (tmp.Length > 7) break;
                

            }

            if (tmp =="") Console.WriteLine("YES");
            else Console.WriteLine("NO");
           







        }

       
       

    }

 
    
}