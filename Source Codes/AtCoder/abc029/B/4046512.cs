using System;
using System.Collections.Generic;
using System.Linq;

namespace at
{
    class Program
    {
        static void Main(string[] args)
        {
            int cnt = 0;
            for (int i = 0; i < 12; i++)
            {
                string str = Console.ReadLine();
                if(str.Contains("r"))
                {
                    cnt = cnt + 1;
                }
            }
            Console.WriteLine(cnt);
        }
    }
}