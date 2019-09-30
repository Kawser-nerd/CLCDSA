using System;

namespace _116_ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] Input = Read();
            uint AB = uint.Parse(Input[0]);
            uint BC = uint.Parse(Input[1]);

            Console.WriteLine(AB * BC * 0.5);

        }

        static string[] Read()
        {
            return Console.ReadLine().Split(' ');
        }
    }
}