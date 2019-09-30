using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var s = new List<string>();
            for (int i = 0; i < n; i++)
            {
                s.Add(Console.ReadLine());
            }

            s.Sort();

            var name = string.Empty;
            var maxName = string.Empty;
            var maxCount = 0;
            foreach (var item in s)
            {
                if (item == name)
                {
                    continue;
                }
                else
                {
                    var count = s.Where(x => x == item).Count();
                    if (count > maxCount)
                    {
                        maxCount = count;
                        maxName = item;
                    }
                    name = item;
                }
            }

            Console.WriteLine(maxName);
        }
    }
}