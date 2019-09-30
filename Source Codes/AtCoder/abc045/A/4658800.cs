using System;

namespace abc045A
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int a = Int32.Parse(Console.ReadLine());
            int b = Int32.Parse(Console.ReadLine());
            int h = Int32.Parse(Console.ReadLine());
            int X = (a + b) * h / 2;
            Console.WriteLine(X.ToString());
        }
    }
}