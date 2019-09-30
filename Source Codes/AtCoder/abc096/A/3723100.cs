using System;

namespace Acs
{
    class Program
    {
        static void Main(string[] args)
        {
            //int a, b;
            var ss = Console.ReadLine().Split(' ');
            var a = int.Parse(ss[0]);
            var b = int.Parse(ss[1]);

            Console.WriteLine(a<=b ?a:a-1);
        }
    }
}