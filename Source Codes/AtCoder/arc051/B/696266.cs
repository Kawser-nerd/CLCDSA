using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ARC051
{
    public class B
    {
        private void Run()
        {
            int K = int.Parse(Console.ReadLine().Trim());

            int a = 2;
            int b = 1;
            for (int i = 2; i <= K; i++)
            {
                int temp = a + b;
                b = a;
                a = temp;
            }
            Console.WriteLine("{0} {1}", a, b);
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new B().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}