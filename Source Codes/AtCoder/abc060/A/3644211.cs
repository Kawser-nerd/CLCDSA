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
           if(inputs[0][inputs[0].Length-1]!=inputs[1][0])
           {
               Console.WriteLine("NO");
               return;
           }
           if(inputs[1][inputs[1].Length-1]!=inputs[2][0])
           {
               Console.WriteLine("NO");
               return;
           }
           
           Console.WriteLine("YES");
        }
    }
}