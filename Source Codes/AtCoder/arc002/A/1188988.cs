using System;
namespace TDDExmaples
{
    class Program
    {
        public static String IsLeap(int years)
            => years % 400 == 0 ? "YES" :
               years % 100 == 0 ? "NO" :
               years % 4 == 0 ? "YES" :
               /* else */         "NO";

        static void Main(string[] args)
        {
            Console.WriteLine( IsLeap(int.Parse(Console.ReadLine())) );
        }
    }
}