using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            List<String> S = new List<String>();

            for (int i = 0; i < input[0]; i++)
            {
                S.Add(Console.ReadLine());
            }

            S.Sort();
            StringBuilder sb = new StringBuilder();

            foreach (var item in S)
            {
                sb.Append(item); 
            }

            Console.WriteLine(sb.ToString());
        }
    }
}