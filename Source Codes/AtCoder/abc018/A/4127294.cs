using System;
using System.Collections.Generic;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int A = int.Parse(Console.ReadLine());
            int B = int.Parse(Console.ReadLine());
            int C = int.Parse(Console.ReadLine());

            var list = new List<int> { A, B, C };
            list.Sort();
            list.Reverse();

            Console.WriteLine(list.IndexOf(A)+1);
            Console.WriteLine(list.IndexOf(B)+1);
            Console.WriteLine(list.IndexOf(C)+1);
        }
    }
}