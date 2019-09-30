using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{

    
    class Program
    {
       

        static void Main(string[] args)
        {

            Console.ReadLine();
            int[] data = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            int ans = 0;
            for(int i = 0; i < data.Count(); i++)
            {
                ans += data[i] - 1;
            }

            Console.WriteLine(ans);
        }
    }
}