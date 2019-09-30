using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();
            string input2 = Console.ReadLine();

            // 2?????
            int count = 0;

            // 2??????????
            foreach (var item in input2.Split(' '))
            {
                for (int n = int.Parse(item); n % 2 == 0; n /= 2)
                {
                    count++;
                }
            }

            // ???????
            Console.WriteLine(count);
        }
    }
}