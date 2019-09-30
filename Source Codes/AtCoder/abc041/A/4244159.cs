using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var s = Console.ReadLine();
            int i = int.Parse(Console.ReadLine());
            Console.WriteLine(s.Substring(i - 1, 1));
        }
    }
}