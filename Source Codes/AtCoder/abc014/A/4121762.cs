using System;
using System.Collections.Generic;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());

            int r = a % b;
            if (r != 0)
            {
                int ans = b - r;
                Console.WriteLine(ans);
            }
            else
            {
                Console.WriteLine(0);
            }
        }
    }
}