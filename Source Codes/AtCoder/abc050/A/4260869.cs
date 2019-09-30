using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int A = int.Parse(input[0]);
            var op = input[1];
            int B = int.Parse(input[2]);
            Console.WriteLine(op == "+" ? A + B : A - B);
        }
    }
}