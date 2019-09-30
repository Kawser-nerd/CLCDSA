using System;
using System.Collections.Generic;
using System.Linq;

namespace Beginner005B
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(GetTakoyakiAge().OrderBy(x => x).First());
        }

        private static IEnumerable<int> GetTakoyakiAge()
        {
            int takoyakiCount = int.Parse(Console.ReadLine());

            for (int i = 0; i < takoyakiCount; i++)
            {
                yield return int.Parse(Console.ReadLine());
            }
        }
    }
}