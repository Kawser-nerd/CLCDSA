using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] input = Console.ReadLine().ToCharArray();
            int answer = 0;

            foreach (char num in input)
            {
                if (Convert.ToInt32(num.ToString()) == 1)
                {
                    answer += 1;
                }
            }
            Console.WriteLine(answer);
        }
    }
}