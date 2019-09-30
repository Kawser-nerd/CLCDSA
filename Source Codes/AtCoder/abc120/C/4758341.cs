using System;
using System.Linq;

namespace b120C {
    class Program {
        static void Main(string[] args) {
            var input = Console.ReadLine().Select(c => c.ToString()).Select(byte.Parse).ToList();
            var red = 0;
            var blue = 0;

            foreach (var item in input) {
                if (item == 0) red++;
                else blue++;
            }
            
            Console.WriteLine(Math.Min(red,blue) * 2);
        }
    }
}