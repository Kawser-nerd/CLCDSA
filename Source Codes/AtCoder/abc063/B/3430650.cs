using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace procon
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string[] letter = new string[s.Length];

            for(int i =0;i<s.Length;i++)
            {
                letter[i] = s.Substring(i, 1);
            }

            var query = s
                .GroupBy(x => x)
                .Select(c => new { item = c.Key, count = c.Count() })
                .Where(a => a.count > 1)
                .Select(a => a);

            string result = "no";
            if (query == null || !query.Any())
            {
                result = "yes";
            }
                Console.WriteLine(result);
            
        }
    }
}