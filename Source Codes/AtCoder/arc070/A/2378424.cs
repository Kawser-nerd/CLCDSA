using System;
using System.Linq;

namespace ARC070
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var X = int.Parse(Console.ReadLine());
            var ans = Enumerable.Range(0, X).TakeWhile(i => i * (i + 1) / 2 < X).Count();
            Console.WriteLine(ans);
        }
    }
}