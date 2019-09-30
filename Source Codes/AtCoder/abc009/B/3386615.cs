using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] input = new int[n];
            for(int i = 0; i< n; i++)
            {
                input[i] = int.Parse(Console.ReadLine());
            }

            var query = input
                .Select(x => new { item = x})
                .GroupBy(c => c.item)
                .OrderByDescending(a => a.Key)
                .ToList();

            Console.WriteLine(query[1].Key);
        }
    }
}