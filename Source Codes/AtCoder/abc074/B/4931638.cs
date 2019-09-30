using System;
using System.Linq;

namespace B___Collecting_Balls__Easy_Version_
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var K = int.Parse(Console.ReadLine());
            var Xi = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int res = 0;

            foreach (var x in Xi)
                res += Math.Min(x * 2, Math.Abs(x - K) * 2);

            Console.WriteLine(res);
        }
    }
}