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
            int n = int.Parse(Console.ReadLine());
            int[] height = new int[n];

            string[] input = Console.ReadLine().Split(' ');
            for(int i = 0;i<n;i++)
            {
                height[i] = int.Parse(input[i]);
            }

            var query = height
                .Select((x, i) => new { height = x, index = i + 1 })
                .OrderByDescending(c => c.height)
                .Select(c => c.index);

            foreach(int temp in query)
            {
                Console.WriteLine(temp);
            }
        }
    }
}