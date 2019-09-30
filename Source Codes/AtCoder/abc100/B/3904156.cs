using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{


    class Program
    {


        static void Main(string[] args)
        {

            string[] str = Console.ReadLine().Split(' ');
            int D = int.Parse(str[0]);
            int K = int.Parse(str[1]);

            string ans = "";           

            for(int i = 1; i <= D; i++)
            {
                ans += "00";
            }

            if (K == 100) K++;

            Console.WriteLine($"{K}" + ans);
            

        }
    }
}