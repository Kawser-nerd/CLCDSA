using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int l = int.Parse(input[1]);
            string[] letter = new string[n];

            for(int i = 0;i < n;i++)
            {
                letter[i] = Console.ReadLine();
            }

            var query = letter
                .OrderBy(x => x)
                .ToList();

            string result = "";
            for(int j = 0;j < n; j++)
            {
                result += query[j];
            }
            Console.WriteLine(result);
        }
    }
}