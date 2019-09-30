using System;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var input = Console.ReadLine().Split(' ').Select(s=>int.Parse(s));

            var count = 0;
            foreach(var item in input)
            {
                var tmpItem = item;
                while(tmpItem % 2==0)
                {
                    tmpItem /= 2;
                    count++;
                }
            }
            Console.WriteLine(count);
        }
    }