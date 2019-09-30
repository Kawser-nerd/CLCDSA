using System;
using System.Collections.Generic;
using System.Linq;
namespace CsProgramSpace
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            List<int> li = RLl();
            int max = li.Max();
            int lon = li.IndexOf(max);
            int sum = 0;
            for(int i = 0; i<n;i++)
            {
                if (i == lon) continue;
                sum += li[i];
            }
            if (max < sum)
                Console.WriteLine("Yes");
            else
                Console.WriteLine("No");
        }
        private static List<int> RLl() => Console.ReadLine().Split(' ').Select(_ => int.Parse(_)).ToList();
    }
}