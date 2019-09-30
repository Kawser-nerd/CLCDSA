using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var s = Console.ReadLine();
            var ans = s.Split(',');
            Console.WriteLine(string.Join(" ", ans));
        }
    }
}