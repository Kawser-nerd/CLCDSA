using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = line[0], M = line[1], X = line[2], left = 0, right = 0;
            var A = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

            foreach(var i in A)
            {
                if (i <= X) left++;
                else right++;
            }            

            Console.WriteLine(left < right ? left : right);
        }
    }
}