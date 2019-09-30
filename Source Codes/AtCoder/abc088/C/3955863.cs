using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{
   
    class Program
    {
        
        static void Main(string[] args)
        {
            var c = new int[3, 3];
            for(int i = 0; i < 3; i++)
            {
                string[] str = Console.ReadLine().Split(' ');
                for(int j = 0; j < 3; j++)
                {
                    c[i, j] = int.Parse(str[j]);
                }
            }

            int[] a = new int[3];
            int[] b = new int[3];

            a[0] = 0;

            //a[0]??????1???b????
            for(int j = 0; j < 3; j++)
            {
                b[j] = c[0, j] - a[0];
            }

            //???b[0]?1??????a????
            for(int i = 1; i < 3; i++)
            {
                a[i] = c[i, 0] - b[0];
            }

            //????
            for(int i = 1; i < 3; i++)
            {
                for(int j = 1; j < 3; j++)
                {
                    if(a[i] + b[j] != c[i, j])
                    {
                        Console.WriteLine("No");
                        return;
                    }
                }
            }

            Console.WriteLine("Yes");

        }
    }
}