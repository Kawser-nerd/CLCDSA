using System;
using System.Collections.Generic;

namespace ABC103C
{
    class MainClass
    {
        public static void Main(string[] args)
        {
        int N = int.Parse(Console.ReadLine());
            string[] input1 = Console.ReadLine().Split(' ');
            int ans = 0;
            for(int i = 0; i < N; i++)
            {
                ans += int.Parse(input1[i]) - 1;
            }
            Console.WriteLine(ans);
        }
    }
}