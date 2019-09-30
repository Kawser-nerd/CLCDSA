using System;
using System.Collections.Generic;

namespace AtTest.D_Challenge
{
    class ABC_001
    {
        static void Main(string[] args)
        {
            Method(args);
            //Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
          int h2=int.Parse(Console.ReadLine());
          Console.WriteLine(n-h2);
        }
    }
}