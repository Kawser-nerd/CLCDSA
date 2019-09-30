using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC41
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());

            var a = Console.ReadLine().Split().Select(int.Parse).ToArray();

            var b = new SortedDictionary<int, int>();
            for (int i = 0; i < n; i++)
            {
                b.Add(i, a[i]);
            }
            
            foreach (var item in b.OrderBy(x => -x.Value))
            {
                Console.WriteLine(item.Key+1);
            }
        }
    }
}