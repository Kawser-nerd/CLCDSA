using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int X = int.Parse(Console.ReadLine());
            Console.WriteLine(X==3||X==5||X==7?"YES":"NO");
        }
    }
}