using System;
using System.Linq;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {

            int n = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');
            int[] height = new int[n];

            for(int i = 0; i < n; i++)
            {
                height[i] = int.Parse(input[i]);
            }

            var query = height
                .Select((x, j) => new { Height = x, index = j + 1 })
                .OrderByDescending(x => x.Height);

            foreach (var result in query)
            {
                Console.WriteLine(result.index);
            }
                

        }
    }
}