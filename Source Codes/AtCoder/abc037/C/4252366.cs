using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace problem
{
    class Program
    {
        void slove()
        {
            var inputs = Console.ReadLine().Split();
            int n = int.Parse(inputs[0]);
            int k = int.Parse(inputs[1]);
            int m = Math.Min(n - k + 1, k);
            var array = Console.ReadLine().Split().Select(int.Parse).ToArray();
            long sum =
                array
                .Select((x, i) => (long)x * (i < m ? i + 1 : n - i < m ? n - i : m))
                //.Select(x => {System.Console.WriteLine(x); return x;})
                .Sum();
            System.Console.WriteLine(sum);
        }
        static void Main(string[] args)
        {
            //Console.SetIn(new StreamReader("input.txt"));
            new Program().slove();
        }
    }
}