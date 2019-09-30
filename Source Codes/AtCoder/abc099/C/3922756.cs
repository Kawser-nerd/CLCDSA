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

            int ans = N;
            for(int i = 0; i <= N; i++)
            {

                int t = i;                
                int cc = 0;
                while (t > 0)
                {
                    cc += t % 6;
                    t = t / 6;
                }               
                
                t = N - i;               
                while (t > 0)
                {
                    cc += t % 9;
                    t = t / 9;
                }

                if (ans > cc) ans = cc;
            }

            Console.WriteLine(ans);

        }
    }
}