using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC085_B
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            HashSet<int> set = new HashSet<int>();

            for (int i = 0; i < n; ++i)
            {
                int diameter = int.Parse(Console.ReadLine());

                set.Add(diameter);
            }

            Console.WriteLine($"{set.Count()}");
        }
    }
}