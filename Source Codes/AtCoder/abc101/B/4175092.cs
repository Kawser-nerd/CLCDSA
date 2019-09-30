using System;
using System.Collections.Generic;

namespace ConsoleApp6
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Console.ReadLine();

            var sn = 0;

            for (int i = 0; i < n.Length; i++)
            {
                sn += int.Parse(n[i].ToString());
            }

            if(int.Parse(n)%sn==0)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}