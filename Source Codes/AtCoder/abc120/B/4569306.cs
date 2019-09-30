using System;
using System.Collections.Generic;
using System.Linq;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }

        static void MainStream()
        {
            var array = new List<int>();
            string[] a_b_k = Console.ReadLine().Split(' ');
            int a = int.Parse(a_b_k[0]);
            int b = int.Parse(a_b_k[1]);
            int k = int.Parse(a_b_k[2]);

            for(var i=1;i<=a;i++)
            {
                if(a%i==0 && b%i==0)
                {
                    array.Add(i);
                }
            }

            Console.WriteLine(array[array.Count - k]);
        }



    }
}