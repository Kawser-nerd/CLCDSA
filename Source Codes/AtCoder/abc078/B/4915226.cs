using System;
using System.Linq;

namespace B___ISU
{
    class Program
    {
        static void Main(string[] args)
        {
            var X_Y_Z = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var X = X_Y_Z[0];
            var Y = X_Y_Z[1];
            var Z = X_Y_Z[2];

            Console.WriteLine((X - Z) / (Y + Z));
        }
    }
}