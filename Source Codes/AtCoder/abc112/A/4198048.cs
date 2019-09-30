using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Main
{
    class Program
    {
        static void Main(string[] arg)
        {
            int answer = 0;
            int n = int.Parse(Console.ReadLine());
            //int[] ta = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            if (n == 2)
            {
                int a = int.Parse(Console.ReadLine());
                int b = int.Parse(Console.ReadLine());
                answer = a + b;
                Console.WriteLine(answer);

            }
            else
            {
                Console.WriteLine("Hello World");
            }
            Console.ReadLine();

        }
    }
}