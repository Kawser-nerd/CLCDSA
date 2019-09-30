using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A.ABC333
{
    class Program
    {
        static void Main(string[] args)
        {
            var AB = Console.ReadLine().Split(null).Select(x => int.Parse(x)).ToArray();

            if (AB.Where(x => x % 2 == 0).Any())
                Console.WriteLine("No");
            else
                Console.WriteLine("Yes");
        }
    }
}