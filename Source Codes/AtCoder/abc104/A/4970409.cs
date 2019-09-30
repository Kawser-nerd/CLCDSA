using System;

namespace ABC
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            ABC104_A();
        }

        static void ABC104_A()
        {
            var R = int.Parse(Console.ReadLine());
            if (R < 1200)
                Console.WriteLine("ABC");
            else if (R < 2800)
                Console.WriteLine("ARC");
            else
                Console.WriteLine("AGC");
        }
    }
}