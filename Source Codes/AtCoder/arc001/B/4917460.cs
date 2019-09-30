using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


namespace AtC
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            var counts = new int[4];
            Console.ReadLine().Select(val => val - '1').ForEach(val => counts[val]++);
            int min = int.MaxValue;
            int max = int.MinValue;
            foreach (var count in counts)
            {
                if (count < min) min = count;
                if (count > max) max = count;
            }

            Console.WriteLine($"{max} {min}");
        }
    }

    static class EnumerableExtension
    {
        public delegate void Function<in T>(T val);

        public static void ForEach<T>(this IEnumerable<T> enumerable, Function<T> function)
        {
            foreach (var x in enumerable)
            {
                function(x);
            }
        }
    }
}