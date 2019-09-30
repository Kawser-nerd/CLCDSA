using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] list = Console.ReadLine().Split();
            int sum = 0;
            int max = 0;

            for (var i = 0; i < n;i++)
            {
                int useNum = int.Parse(list[i]);
                sum += useNum;
                if(useNum > max)
                {
                    max = useNum;
                }
            }
            if(max<sum-max)
            {
                Console.WriteLine("Yes");
            }else{
                Console.WriteLine("No");
            }
        }
    }
}