using System;
using System.Linq;

namespace AGC021
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var N = Console.ReadLine().ToCharArray();

            var ans = N.Sum(c => c - '0');
            for (var i = N.Length - 2; i >= 0; i--)
            {
                N[i]--;
                N[i + 1] = '9';
                ans = Math.Max(ans, N.Sum(c => c - '0'));
            }

            Console.WriteLine(ans);
        }
    }
}