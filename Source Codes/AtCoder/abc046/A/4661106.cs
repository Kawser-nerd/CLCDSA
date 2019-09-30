using System;
using System.Linq;

namespace abc046A
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split();
            int a = int.Parse(str[0]);
            int b = int.Parse(str[1]);
            int c = int.Parse(str[2]);
            if (a == b && b == c)
                Console.WriteLine(1);
            else if (a == b)
                Console.WriteLine(2);
            else if (a == c)
                Console.WriteLine(2);
            else if (b == c)
                Console.WriteLine(2);
            else
                Console.WriteLine(3);
        }
    }
}