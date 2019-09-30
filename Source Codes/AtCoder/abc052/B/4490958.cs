using System;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            var S = Console.ReadLine().ToArray();
            var max = 0;
            var result = 0;

            foreach(var c in S)
            {
                result += c == 'I' ? 1 : -1;
                if (max < result) max = result;
            }
            Console.WriteLine(max);
        }
    }