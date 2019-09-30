using System;

namespace ABC066B
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();

            do
            {
                str = str.Substring(0, str.Length - 2);
            } while (!str.Substring(str.Length / 2).Equals(str.Substring(0, str.Length / 2)));

            Console.WriteLine(str.Length);
        }
    }
}