using System;
using System.Collections.Generic;
using System.Linq;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int A = int.Parse(Console.ReadLine());
            int y = 0;
            int num = 0;
            var list = new List<int> { };
            for (int x = 1; x <= A; x++)
            {
                y = A - x;
                num = x * y;
                list.Add(num);
            }
            int max = list.Max();
            Console.WriteLine(max);
        }
    }
}