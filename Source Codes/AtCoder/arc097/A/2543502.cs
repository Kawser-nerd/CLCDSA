using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            String input = Console.ReadLine();
            int num = int.Parse(Console.ReadLine());

            HashSet<String> set = new HashSet<String>();

            int max_len = 5;

            for (int i = 1; i <= max_len; i++)
            {
                for (int j = 0; j <= input.Length - i; j++)
                {
                    set.Add(input.Substring(j, i));
                }
            }
            Console.WriteLine(set.OrderBy(s => s).ElementAt(num - 1));

        }
    }
}