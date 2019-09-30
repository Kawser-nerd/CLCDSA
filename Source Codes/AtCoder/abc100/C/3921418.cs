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
            long[] data = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();

            int ans = 0;
            for(int i = 0; i < N; i++)
            {
                while(data[i] % 2 == 0)
                {
                    ans++;
                    data[i] /= 2;
                }
               
            }

            Console.WriteLine(ans);

        }
    }
}