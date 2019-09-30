using System;
using System.Linq;


namespace AtC
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var countOne = S.Count(val => val  == '1');
            var countZero = S.Count(val => val == '0');
            Console.WriteLine(S.Length - Math.Abs(countOne - countZero));
        }
    }
}