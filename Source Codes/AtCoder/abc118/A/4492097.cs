using System;

namespace _118_ABC
{
    class Program01
    {
        static void Main(string[] args)
        {
            string[] Input = Console.ReadLine().Split(' ');
            int A = int.Parse(Input[0]);
            int B = int.Parse(Input[1]);

            Console.WriteLine(B % A == 0 ? A + B : B - A);            
        }
    }
}