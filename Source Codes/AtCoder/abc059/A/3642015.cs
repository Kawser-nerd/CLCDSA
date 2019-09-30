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
           foreach(var input in inputs)
           {
               Console.Write(input.ToUpper()[0]);
           }
           Console.WriteLine();
        }
    }
}