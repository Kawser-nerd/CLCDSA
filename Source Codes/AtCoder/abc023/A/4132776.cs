using System;
namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int X = int.Parse(Console.ReadLine());
            int n1 = X / 10;
            int n2 = X % 10;
            Console.WriteLine(n1 + n2);
        }
    }
}