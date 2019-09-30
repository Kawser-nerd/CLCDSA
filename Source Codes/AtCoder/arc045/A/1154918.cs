using System;

namespace arc045_a
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            s = s.Replace("Left", "<");
            s = s.Replace("Right", ">");
            s = s.Replace("AtCoder", "A");
            Console.WriteLine(s);
        }
    }
}