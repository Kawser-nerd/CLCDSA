using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
 
class Test
{
   public static void Main(string[] args)
   {
       int total = int.Parse( Console.ReadLine() );
       int ng1 =  int.Parse( Console.ReadLine() );
       int ng2 = int.Parse( Console.ReadLine() );
       int ng3 = int.Parse( Console.ReadLine() );
       List<int> ngs = new List<int>{ng1,ng2,ng3};
       ngs.Sort();
       
       int temp = 300 - total;
       string text = "";
       
       if(total == ng1 || total == ng2 || total == ng3)
       {
           text = "NO";
       }
       else
       {
            for(int i = 0; i < 100;i++)
            {
                total -= 3;
               if(ngs[0] == total){total++; temp--;}
                if(ngs[1] == total){total++; temp--;}
            if(ngs[2] == total){total++; temp--;}
            }
           text = temp < 0 ? "NO" : "YES";
       }
       
       
       Console.WriteLine(text);
   }
}