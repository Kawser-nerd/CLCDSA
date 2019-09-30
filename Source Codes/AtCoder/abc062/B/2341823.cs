using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.Globalization;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var data = new List<string>();
            for(int i = 0; i < a[0]; i++)
            {
                data.Add(Console.ReadLine());
            }
            Console.Write("#");
            for (int i = 0; i < a[1]; i++)
            {
                Console.Write("#");
            }
            Console.Write("#\n");

            for (int i = 0; i < a[0]; i++)
            {
                Console.WriteLine($"#{data[i]}#");
            }
            Console.Write("#");
            for (int i = 0; i < a[1]; i++)
            {
                Console.Write("#");
            }
            Console.Write("#\n");
        }
    }
}