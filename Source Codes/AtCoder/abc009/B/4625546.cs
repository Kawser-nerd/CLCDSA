using System;
using System.Collections.Generic;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            var list = new SortedSet<int>();

            for(int i = 0; i < N; i++)
            {
                int A = int.Parse(Console.ReadLine());
                list.Add(A);
            }
            list.Remove(list.Max);
            Console.WriteLine(list.Max);
        }
    }
}