using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Console.ReadLine();
            var n1 = n.Replace("1", "a");
            var n2 = n1.Replace("9", "1");
            var n3 = n2.Replace("a", "9");
            Console.WriteLine(n3);
        }
    }
}