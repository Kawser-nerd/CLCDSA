using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace tes2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] s = new string[n];

            for(int i = 0;i<n;i++)
            {
                s[i] = Console.ReadLine();
            }

            var count = s
                .GroupBy(x => x)
                .Select(c => new { item = c.Key, count = c.Count() })
                .OrderByDescending(a => a.count)
                .ToList();

            Console.WriteLine(count[0].item);
        }
    }
}