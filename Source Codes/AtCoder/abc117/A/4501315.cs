using System;

namespace _117_ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] Input = Console.ReadLine().Split(' ');
            double T = double.Parse(Input[0]);
            double X = double.Parse(Input[1]);

            Console.WriteLine(T / X);
        }
    }
}