using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = int.Parse(Console.ReadLine());

            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100-i; j++)
                {
                    if (4 * i + j * 7 == input)
                    {
                        Console.WriteLine("Yes");
                        return;
                    }
                }
            }
            Console.WriteLine("No");

        }
    }
}