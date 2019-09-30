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
            var input = Console.ReadLine().Split(' ').Select(x=>int.Parse(x)).ToArray();

            int[] m = new int[input[0]];
            for (int i = 0; i < input[0]; i++)
            {
                m[i] = int.Parse(Console.ReadLine());
                
            }

            var sum = m.Sum();
            var min = m.Min();
            
            var answer = (input[1] - sum) / min+ input[0];



            Console.WriteLine(answer);

        }
    }
}