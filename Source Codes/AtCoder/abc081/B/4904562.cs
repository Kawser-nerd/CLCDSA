using System;
using System.Linq;

namespace B___Shift_only
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var Ai = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var cnt = 0;

            while (Ai.All(x => x % 2 == 0))
            {
                Ai = Ai.Select(x => x / 2).ToArray();
                cnt++;
            }
            Console.WriteLine(cnt);
        }
    }
}