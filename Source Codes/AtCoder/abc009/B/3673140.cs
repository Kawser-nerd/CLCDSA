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
            var a = new List<int>();
            for (int i = 0; i < n; i++)
            {
                a.Add(int.Parse(Console.ReadLine()));
            }

            a.Sort((A, B) => B - A);
            Console.WriteLine(a.Distinct().Skip(1).First());
        }
    }
}