using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{ 

    class Program
    {

        
        
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            string ans = "";

            while(N != 0)
            {
                if (N % 2 != 0)
                {
                    N--;
                    ans = "1" + ans;
                }
                else ans = "0" + ans;
                N /= -2;

            }

            if (ans == "") ans = "0";

            Console.WriteLine(ans);

        }
    }
}