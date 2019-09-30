using System;
using System.Linq;

namespace A.Something_on_It
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine().ToCharArray();
            int ans = 700 + S.Count(x => x == 'o') * 100;

            Console.WriteLine(ans);
        }
    }
}