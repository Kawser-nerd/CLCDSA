using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace CSharp_Shell
{

    public static class Program 
    {
        public static void Main() 
        {
           var inputs=Console.ReadLine().Split();
           var a=int.Parse(inputs[0]);
           var b=int.Parse(inputs[1]);
           var c=int.Parse(inputs[2]);
           
           for(var i=0;i<b;i++)
           {
               if(a%b*i%b==c){Console.WriteLine("YES"); return;}
           }
           
           Console.WriteLine("NO");
        }
    }
}