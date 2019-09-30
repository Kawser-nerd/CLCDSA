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

            int[] data = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int D = data[0];
            int X = data[1];

            int cnt = 0;
            for(int i = 1; i <= N; i++)
            {
                int a = int.Parse(Console.ReadLine());

                for(int j = 0; ; j++)
                {
                    if (j * a + 1 <= D) cnt++;
                    else break;
                }

            }

            Console.WriteLine(X + cnt);
            


        }
    }
}