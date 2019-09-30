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
           var a=Console.ReadLine();
           var b=Console.ReadLine();
           if(a.Length<b.Length){Console.WriteLine("LESS"); return;}
           if(a.Length>b.Length){Console.WriteLine("GREATER"); return;}
           
           for(var i=0; i<a.Length; i++)
           {
               if(a[i]<b[i]){Console.WriteLine("LESS"); return;}
               if(a[i]>b[i]){Console.WriteLine("GREATER"); return;}
           }
           
           Console.WriteLine("EQUAL");
        }
    }
}